// generated by Fast Light User Interface Designer (fluid) version 1.0104

#include "alignment_panel.h"

Fl_Window *project_window=(Fl_Window *)0;

static void cb_Close(Fl_Button*, void*) {
  project_window->hide();
}

Fl_Input *header_file_input=(Fl_Input *)0;

Fl_Input *code_file_input=(Fl_Input *)0;

Fl_Light_Button *include_H_from_C_button=(Fl_Light_Button *)0;

Fl_Choice *i18n_type_chooser=(Fl_Choice *)0;

Fl_Menu_Item menu_i18n_type_chooser[] = {
 {"None", 0,  0, 0, 0, 0, 0, 14, 56},
 {"GNU gettext", 0,  0, 0, 0, 0, 0, 14, 56},
 {"POSIX catgets", 0,  0, 0, 0, 0, 0, 14, 56},
 {0}
};

Fl_Input *i18n_include_input=(Fl_Input *)0;

Fl_Input *i18n_file_input=(Fl_Input *)0;

Fl_Input *i18n_set_input=(Fl_Input *)0;

Fl_Input *i18n_function_input=(Fl_Input *)0;

Fl_Window* make_project_window() {
  Fl_Window* w;
  { Fl_Window* o = project_window = new Fl_Window(365, 210, "Project Settings");
    w = o;
    { Fl_Button* o = new Fl_Button(295, 175, 60, 25, "Close");
      o->tooltip("Close this dialog.");
      o->callback((Fl_Callback*)cb_Close);
    }
    { Fl_Tabs* o = new Fl_Tabs(10, 10, 345, 155);
      { Fl_Group* o = new Fl_Group(10, 35, 345, 130, "Output");
        { Fl_Box* o = new Fl_Box(25, 45, 325, 15, "Use \"name.ext\" to set name or just \".ext\" to set only extension.");
          o->labelsize(10);
          o->align(132|FL_ALIGN_INSIDE);
        }
        { Fl_Input* o = header_file_input = new Fl_Input(105, 65, 245, 20, "Header File:");
          o->tooltip("The name of the generated header file.");
          o->box(FL_THIN_DOWN_BOX);
          o->textfont(4);
          o->callback((Fl_Callback*)header_input_cb, (void*)(1));
          o->when(FL_WHEN_CHANGED);
        }
        { Fl_Input* o = code_file_input = new Fl_Input(105, 95, 245, 20, "Code File:");
          o->tooltip("The name of the generated code file.");
          o->box(FL_THIN_DOWN_BOX);
          o->textfont(4);
          o->callback((Fl_Callback*)code_input_cb, (void*)(1));
          o->when(FL_WHEN_CHANGED);
        }
        { Fl_Light_Button* o = include_H_from_C_button = new Fl_Light_Button(105, 125, 170, 20, "Include Header from Code");
          o->tooltip("Include the header file from the code file.");
          o->value(1);
          o->labelsize(12);
          o->callback((Fl_Callback*)include_H_from_C_button_cb);
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(10, 35, 345, 130, "Internationalization");
        o->hide();
        { Fl_Choice* o = i18n_type_chooser = new Fl_Choice(100, 45, 125, 20, "Use:");
          o->tooltip("Type of internationalization to use.");
          o->box(FL_THIN_UP_BOX);
          o->down_box(FL_BORDER_BOX);
          o->callback((Fl_Callback*)i18n_type_cb);
          o->menu(menu_i18n_type_chooser);
        }
        { Fl_Input* o = i18n_include_input = new Fl_Input(100, 75, 245, 20, "#include:");
          o->tooltip("The include file for internationalization.");
          o->box(FL_THIN_DOWN_BOX);
          o->textfont(4);
          o->callback((Fl_Callback*)i18n_text_cb);
        }
        { Fl_Input* o = i18n_file_input = new Fl_Input(100, 105, 245, 20, "File:");
          o->tooltip("The name of the message catalog.");
          o->box(FL_THIN_DOWN_BOX);
          o->textfont(4);
          o->callback((Fl_Callback*)i18n_text_cb);
        }
        { Fl_Input* o = i18n_set_input = new Fl_Input(100, 135, 245, 20, "Set:");
          o->tooltip("The message set number.");
          o->type(2);
          o->box(FL_THIN_DOWN_BOX);
          o->textfont(4);
          o->callback((Fl_Callback*)i18n_text_cb);
        }
        { Fl_Input* o = i18n_function_input = new Fl_Input(100, 105, 245, 20, "Function:");
          o->tooltip("The function to call to internationalize the labels and tooltips.");
          o->box(FL_THIN_DOWN_BOX);
          o->textfont(4);
          o->callback((Fl_Callback*)i18n_text_cb);
        }
        o->end();
      }
      o->end();
    }
    o->set_modal();
    o->end();
  }
  return w;
}
Fl_Text_Buffer *shell_run_buffer;

Fl_Window *settings_window=(Fl_Window *)0;

static void cb_Close1(Fl_Button*, void*) {
  settings_window->hide();
}

Fl_Check_Button *tooltips_button=(Fl_Check_Button *)0;

static void cb_tooltips_button(Fl_Check_Button*, void*) {
  Fl_Tooltip::enable(tooltips_button->value());
fluid_prefs.set("show_tooltips", tooltips_button->value());
}

Fl_Check_Button *completion_button=(Fl_Check_Button *)0;

static void cb_completion_button(Fl_Check_Button*, void*) {
  fluid_prefs.set("show_completion_dialogs", completion_button->value());
}

Fl_Check_Button *openlast_button=(Fl_Check_Button *)0;

static void cb_openlast_button(Fl_Check_Button*, void*) {
  fluid_prefs.set("open_previous_file", openlast_button->value());
}

Fl_Check_Button *prevpos_button=(Fl_Check_Button *)0;

static void cb_prevpos_button(Fl_Check_Button*, void*) {
  fluid_prefs.set("prev_window_pos", prevpos_button->value());
}

Fl_Window* make_settings_window() {
  Fl_Window* w;
  { Fl_Window* o = settings_window = new Fl_Window(255, 210, "GUI Settings");
    w = o;
    { Fl_Button* o = new Fl_Button(185, 179, 60, 25, "Close");
      o->tooltip("Close this dialog.");
      o->callback((Fl_Callback*)cb_Close1);
    }
    { Fl_Tabs* o = new Fl_Tabs(10, 10, 235, 158);
      { Fl_Group* o = new Fl_Group(10, 35, 235, 133, "GUI:");
        o->align(FL_ALIGN_TOP_LEFT);
        { Fl_Check_Button* o = tooltips_button = new Fl_Check_Button(20, 45, 215, 20, "Show Tooltips");
          o->down_box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_tooltips_button);
          int b;
          fluid_prefs.get("show_tooltips", b, 1);
          tooltips_button->value(b);
          Fl_Tooltip::enable(b);
        }
        { Fl_Check_Button* o = completion_button = new Fl_Check_Button(20, 75, 215, 20, "Show Completion Dialogs");
          o->down_box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_completion_button);
          int b;
          fluid_prefs.get("show_completion_dialogs", b, 1);
          completion_button->value(b);
        }
        { Fl_Check_Button* o = openlast_button = new Fl_Check_Button(20, 105, 215, 20, "Open Previous File on Startup");
          o->down_box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_openlast_button);
          int b;
          fluid_prefs.get("open_previous_file", b, 0);
          openlast_button->value(b);
        }
        { Fl_Check_Button* o = prevpos_button = new Fl_Check_Button(20, 135, 215, 20, "Remember Window Positions");
          o->down_box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_prevpos_button);
          int b;
          fluid_prefs.get("prev_window_pos", b, 1);
          prevpos_button->value(b);
        }
        o->end();
      }
      o->end();
    }
    o->end();
  }
  return w;
}

Fl_Window *shell_window=(Fl_Window *)0;

Fl_Input *shell_command_input=(Fl_Input *)0;

static void cb_shell_command_input(Fl_Input*, void*) {
  fluid_prefs.set("shell_command", shell_command_input->value());
}

Fl_Check_Button *shell_savefl_button=(Fl_Check_Button *)0;

static void cb_shell_savefl_button(Fl_Check_Button*, void*) {
  fluid_prefs.set("shell_savefl", shell_savefl_button->value());
}

Fl_Check_Button *shell_writecode_button=(Fl_Check_Button *)0;

static void cb_shell_writecode_button(Fl_Check_Button*, void*) {
  fluid_prefs.set("shell_writecode", shell_writecode_button->value());
}

Fl_Check_Button *shell_writemsgs_button=(Fl_Check_Button *)0;

static void cb_shell_writemsgs_button(Fl_Check_Button*, void*) {
  fluid_prefs.set("shell_writemsgs", shell_writemsgs_button->value());
}

static void cb_Cancel(Fl_Button*, void*) {
  shell_window->hide();
}

Fl_Window *shell_run_window=(Fl_Window *)0;

Fl_Return_Button *shell_run_button=(Fl_Return_Button *)0;

static void cb_shell_run_button(Fl_Return_Button*, void*) {
  shell_run_window->hide();
}

Fl_Text_Display *shell_run_display=(Fl_Text_Display *)0;

Fl_Window* make_shell_window() {
  Fl_Window* w;
  { Fl_Window* o = shell_window = new Fl_Window(450, 145, "Shell Command");
    w = o;
    { Fl_Tabs* o = new Fl_Tabs(10, 10, 430, 90);
      { Fl_Group* o = new Fl_Group(10, 30, 430, 70, "Shell Command");
        o->align(FL_ALIGN_TOP_LEFT);
        { Fl_Input* o = shell_command_input = new Fl_Input(20, 40, 410, 20);
          o->callback((Fl_Callback*)cb_shell_command_input);
          char buf[1024];
          fluid_prefs.get("shell_command", buf, "", sizeof(buf));
          shell_command_input->value(buf);
        }
        { Fl_Check_Button* o = shell_savefl_button = new Fl_Check_Button(20, 65, 110, 20, "Save .FL File");
          o->down_box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_shell_savefl_button);
          int b;
          fluid_prefs.get("shell_savefl", b, 1);
          shell_savefl_button->value(b);
        }
        { Fl_Check_Button* o = shell_writecode_button = new Fl_Check_Button(140, 65, 95, 20, "Write Code");
          o->down_box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_shell_writecode_button);
          int b;
          fluid_prefs.get("shell_writecode", b, 1);
          shell_writecode_button->value(b);
        }
        { Fl_Check_Button* o = shell_writemsgs_button = new Fl_Check_Button(245, 65, 130, 20, "Write Messages");
          o->down_box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_shell_writemsgs_button);
          int b;
          fluid_prefs.get("shell_writemsgs", b, 0);
          shell_writemsgs_button->value(b);
        }
        o->end();
      }
      o->end();
    }
    { Fl_Button* o = new Fl_Button(375, 110, 65, 25, "Cancel");
      o->callback((Fl_Callback*)cb_Cancel);
    }
    { Fl_Return_Button* o = new Fl_Return_Button(225, 110, 140, 25, "Run Command");
      o->callback((Fl_Callback*)do_shell_command);
    }
    o->end();
  }
  { Fl_Window* o = shell_run_window = new Fl_Window(555, 435, "Shell Command Output");
    w = o;
    { Fl_Return_Button* o = shell_run_button = new Fl_Return_Button(465, 400, 80, 25, "Close");
      o->callback((Fl_Callback*)cb_shell_run_button);
    }
    { Fl_Text_Display* o = shell_run_display = new Fl_Text_Display(10, 10, 530, 380);
      o->textfont(4);
      o->textsize(12);
      Fl_Group::current()->resizable(o);
      shell_run_buffer = new Fl_Text_Buffer();
      shell_run_display->buffer(shell_run_buffer);
    }
    o->end();
  }
  return w;
}

Fl_Window *grid_window=(Fl_Window *)0;

Fl_Input *horizontal_input=(Fl_Input *)0;

Fl_Input *vertical_input=(Fl_Input *)0;

Fl_Input *snap_input=(Fl_Input *)0;

static void cb_Close2(Fl_Button*, void*) {
  grid_window->hide();
}

Fl_Window* make_grid_window() {
  Fl_Window* w;
  { Fl_Window* o = grid_window = new Fl_Window(155, 175, "Grid");
    w = o;
    { Fl_Tabs* o = new Fl_Tabs(10, 10, 135, 120);
      o->align(FL_ALIGN_TOP_LEFT);
      { Fl_Group* o = new Fl_Group(10, 30, 135, 100, "Grid");
        o->align(FL_ALIGN_TOP_LEFT);
        { Fl_Input* o = horizontal_input = new Fl_Input(95, 40, 40, 20, "Horizontal:");
          o->tooltip("Horizontal grid spacing.");
          o->type(2);
          o->box(FL_THIN_DOWN_BOX);
          o->callback((Fl_Callback*)grid_cb, (void*)(1));
          o->when(FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY);
        }
        { Fl_Input* o = vertical_input = new Fl_Input(95, 70, 40, 20, "Vertical:");
          o->tooltip("Vertical grid spacing.");
          o->type(2);
          o->box(FL_THIN_DOWN_BOX);
          o->callback((Fl_Callback*)grid_cb, (void*)(2));
          o->when(FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY);
        }
        { Fl_Input* o = snap_input = new Fl_Input(95, 100, 40, 20, "Snap:");
          o->tooltip("Snap to grid within this many pixels.");
          o->type(2);
          o->box(FL_THIN_DOWN_BOX);
          o->callback((Fl_Callback*)grid_cb, (void*)(3));
          o->when(FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY);
        }
        o->end();
      }
      o->end();
    }
    { Fl_Button* o = new Fl_Button(85, 140, 60, 25, "Close");
      o->tooltip("Close this dialog.");
      o->callback((Fl_Callback*)cb_Close2);
    }
    o->end();
  }
  return w;
}
