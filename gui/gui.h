/**
 * @file gui.h Библиотека работы с GUI.
 */

#ifndef GUI_H
#define	GUI_H

#include "defs/defs.h"
#include "graphics.h"
#include "font.h"

//! Структура темы оформления GUI.
typedef struct _Gui_Theme {
    graphics_color_t back_color; //! Цвет фона.
    graphics_color_t front_color; //! Цвет отрисовки.
    graphics_color_t font_color; //! Цвет шрифта.
    font_t* widget_font; //! Шрифт виджета.
    font_t* menu_font; //! Шрифт меню.
} gui_theme_t;

#define MAKE_GUI_THEME(arg_back_color, arg_front_color, arg_font_color,\
                       arg_widget_font, arg_menu_font)\
        { .back_color = arg_back_color, .front_color = arg_front_color, .font_color = arg_font_color,\
          .widget_font = arg_widget_font, .menu_font = arg_menu_font }

#ifndef GUI_WIDGET_TYPE_DEFINED
#define GUI_WIDGET_TYPE_DEFINED
//! Тип структуры виджета.
typedef struct _Gui_Widget gui_widget_t;
#endif //GUI_WIDGET_TYPE_DEFINED

//! Структура графического интерфейса.
typedef struct _Gui {
    graphics_t* graphics; //!< Графический буфер.
    gui_theme_t* theme; //!< Тема оформления.
    gui_widget_t* root_widget; //!< Корневой виджет.
} gui_t;

#define MAKE_GUI(arg_graphics, arg_theme)\
        { .graphics = arg_graphics, .theme = arg_theme}

/**
 * Инициализирует графический интерфейс.
 * @param gui Графический интерфейс.
 * @param graphics Графический буфер.
 * @param theme Тема графического интерфейса.
 * @return Код ошибки.
 */
extern err_t gui_init(gui_t* gui, graphics_t* graphics, gui_theme_t* theme);

/**
 * Получает графический буфер.
 * @param gui Графический интерфейс.
 * @return Графический буфер.
 */
ALWAYS_INLINE static graphics_t* gui_graphics(gui_t* gui)
{
    return gui->graphics;
}

/**
 * Устанавливает графический буфер.
 * @param gui
 * @param graphics
 * @return Код ошибки.
 */
extern err_t gui_set_graphics(gui_t* gui, graphics_t* graphics);

/**
 * Получает тему оформления.
 * @param gui Графический интерфейс.
 * @return Тема оформления.
 */
ALWAYS_INLINE static gui_theme_t* gui_theme(gui_t* gui)
{
    return gui->theme;
}

/**
 * Устанавливает тему оформления.
 * @param gui
 * @param theme Тема оформления.
 * @return Код ошибки.
 */
extern err_t gui_set_theme(gui_t* gui, gui_theme_t* theme);

/**
 * Получает корневой виджет.
 * @param gui Графический интерфейс.
 * @return Корневой виджет.
 */
ALWAYS_INLINE static gui_widget_t* gui_root_widget(gui_t* gui)
{
    return gui->root_widget;
}

/**
 * Устанавливает корневой виджет.
 * @param gui Графический интерфейс.
 * @param widget Корневой виджет.
 * @return Код ошибки.
 */
extern err_t gui_set_root_widget(gui_t* gui, gui_widget_t* widget);

#endif	/* GUI_H */
