// SPDX-FileCopyrightText: 2024 Louis Moureaux
// SPDX-License-Identifier: GPL-3.0-or-later

#include "tileset_options.h"

#include "name_translation.h"
#include "tileset/tilespec.h"

#include <QCheckBox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>

namespace freeciv {

/**
 * Sets up the tileset options dialog.
 *
 * The dialog contains a series of check boxes, one for each options. They
 * take effect immediately. There is also a close button and a reset button.
 */
tileset_options_dialog::tileset_options_dialog(struct tileset *t,
                                               QWidget *parent)
    : QDialog(parent)
{
  setModal(true);
  setMinimumWidth(300); // For the title to be fully visible
  setWindowTitle(_("Tileset Options"));

  auto layout = new QVBoxLayout;
  setLayout(layout);

  for (const auto &option : tileset_get_options(t)) {
    auto check = new QCheckBox(option.description);

    // Sync check box state with the tileset
    check->setChecked(tileset_option_is_enabled(t, option.name));
    connect(check, &QCheckBox::toggled, [option](bool checked) {
      tileset_set_option(tileset, option.name, checked);
    });

    m_checks[option.name] = check;
    layout->addWidget(check);
  }

  layout->addSpacing(6);

  auto buttons = new QDialogButtonBox(QDialogButtonBox::Close
                                      | QDialogButtonBox::Reset);
  connect(buttons->button(QDialogButtonBox::Close), &QPushButton::clicked,
          this, &QDialog::accept);
  connect(buttons->button(QDialogButtonBox::Reset), &QPushButton::clicked,
          this, &tileset_options_dialog::reset);
  layout->addWidget(buttons);
}

/**
 * Resets all options to the tileset defaults.
 */
void tileset_options_dialog::reset()
{
  for (const auto &option : tileset_get_options(tileset)) {
    // Changes are propagated though the clicked() signal.
    m_checks[option.name]->setChecked(option.enabled_by_default);
  }
}

} // namespace freeciv
