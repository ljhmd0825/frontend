// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: muxstorage

#include "ui.h"

void ui_screen_init(lv_obj_t * ui_pnlContent)
{
    ui_pnlBIOS = lv_obj_create(ui_pnlContent);
    ui_pnlConfig = lv_obj_create(ui_pnlContent);
    ui_pnlCatalogue = lv_obj_create(ui_pnlContent);
    ui_pnlFav = lv_obj_create(ui_pnlContent);
    ui_pnlMusic = lv_obj_create(ui_pnlContent);
    ui_pnlSave = lv_obj_create(ui_pnlContent);
    ui_pnlScreenshot = lv_obj_create(ui_pnlContent);
    ui_pnlTheme = lv_obj_create(ui_pnlContent);

    ui_lblBIOS = lv_label_create(ui_pnlBIOS);
    ui_lblConfig = lv_label_create(ui_pnlConfig);
    ui_lblCatalogue = lv_label_create(ui_pnlCatalogue);
    ui_lblFav = lv_label_create(ui_pnlFav);
    ui_lblMusic = lv_label_create(ui_pnlMusic);
    ui_lblSave = lv_label_create(ui_pnlSave);
    ui_lblScreenshot = lv_label_create(ui_pnlScreenshot);
    ui_lblTheme = lv_label_create(ui_pnlTheme);

    ui_icoBIOS = lv_img_create(ui_pnlBIOS);
    ui_icoConfig = lv_img_create(ui_pnlConfig);
    ui_icoCatalogue = lv_img_create(ui_pnlCatalogue);
    ui_icoFav = lv_img_create(ui_pnlFav);
    ui_icoMusic = lv_img_create(ui_pnlMusic);
    ui_icoSave = lv_img_create(ui_pnlSave);
    ui_icoScreenshot = lv_img_create(ui_pnlScreenshot);
    ui_icoTheme = lv_img_create(ui_pnlTheme);

    ui_droBIOS = lv_dropdown_create(ui_pnlBIOS);
    ui_droConfig = lv_dropdown_create(ui_pnlConfig);
    ui_droCatalogue = lv_dropdown_create(ui_pnlCatalogue);
    ui_droFav = lv_dropdown_create(ui_pnlFav);
    ui_droMusic = lv_dropdown_create(ui_pnlMusic);
    ui_droSave = lv_dropdown_create(ui_pnlSave);
    ui_droScreenshot = lv_dropdown_create(ui_pnlScreenshot);
    ui_droTheme = lv_dropdown_create(ui_pnlTheme);
}