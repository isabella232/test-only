//
// "$Id$"
//
// implementation of Fl_Device and Fl_Abstract_Printer classes for the Fast Light Tool Kit (FLTK).
//
// Copyright 2010 by Bill Spitzak and others.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to:
//
//     http://www.fltk.org/str.php
//

#include <FL/Fl.H>
#include <FL/Fl_Device.H>
#include <FL/Fl_Printer.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>

extern Fl_Device *fl_device;

void Fl_Device::draw(Fl_Pixmap *pxm,int XP, int YP, int WP, int HP, int cx, int cy)
{
  // presently, never gets called
}

void Fl_Device::draw(Fl_Bitmap *bm,int XP, int YP, int WP, int HP, int cx, int cy)
{
  // presently, never gets called
}

void Fl_Device::draw(Fl_RGB_Image *rgb,int XP, int YP, int WP, int HP, int cx, int cy)
{
  // presently, never gets called
}

void Fl_Abstract_Printer::print_widget(Fl_Widget* widget, int delta_x, int delta_y) 
{ 
  int old_x, old_y, new_x, new_y, is_window;
  if ( ! widget->visible() ) return;
  is_window = (widget->as_window() != NULL);
  widget->damage(FL_DAMAGE_ALL);
  // set origin to the desired top-left position of the widget
  origin(&old_x, &old_y);
  new_x = old_x + delta_x;
  new_y = old_y + delta_y;
  if (!is_window) {
    new_x -= widget->x();
    new_y -= widget->y();
  }
  if (new_x != old_x || new_y != old_y) {
    translate(new_x - old_x, new_y - old_y );
  }
  // if widget is a window, clip all drawings to the window area
  if (is_window) fl_push_clip(0, 0, widget->w(), widget->h() );
  // we do some trickery to recognize OpenGL windows and draw them via a plugin
  int drawn_by_plugin = 0;
  if (widget->as_gl_window()) {
    Fl_Plugin_Manager pm("fltk:device");  
    Fl_Device_Plugin *pi = (Fl_Device_Plugin*)pm.plugin("opengl.device.fltk.org");
    if (pi) drawn_by_plugin = pi->print(this, widget, 0, 0);
  }
  if (!drawn_by_plugin) {
    widget->draw();
  }
  if (is_window) fl_pop_clip();
  // find subwindows of widget and print them
  traverse(widget);
  // reset origin to where it was
  if (new_x != old_x || new_y != old_y) {
    untranslate();
  }
}


void Fl_Abstract_Printer::traverse(Fl_Widget *widget)
{
  Fl_Group *g = widget->as_group();
  if (!g) return;
  int n = g->children();
  for (int i = 0; i < n; i++) {
    Fl_Widget *c = g->child(i);
    if ( !c->visible() ) continue;
    if ( c->as_window() ) {
      print_widget(c, c->x(), c->y());
    }
    else traverse(c);
  }
}

void Fl_Abstract_Printer::origin(int *x, int *y)
{
  if (x) *x = x_offset;
  if (y) *y = y_offset;
}

void Fl_Abstract_Printer::print_window_part(Fl_Window *win, int x, int y, int w, int h, int delta_x, int delta_y)
{
  int slice, width, offset, count = 0;
  Fl_Device::display_device()->set_current();
  Fl_Window *save_front = Fl::first_window();
  win->show();
  fl_gc = NULL;
  Fl::check();
  win->make_current();
  uchar *image_data[20];
#ifdef WIN32 // because of bug in StretchDIBits, vertically cut image in pieces of width slice
  slice = 500;
#else
  slice = w;
#endif
  for ( offset = 0; offset < w; offset += slice) {
    width = slice; 
    if (offset + width > w) width = w - offset;
    image_data[count++] = fl_read_image(NULL, x + offset, y, width, h);
    }  
  save_front->show();
  this->set_current();
  for ( int i = 0, offset = 0; i < count; i++, offset += slice) {
    width = slice; 
    if (offset + width > w) width = w - offset;
    fl_draw_image(image_data[i], delta_x + offset, delta_y, width, h, 3);
#ifdef __APPLE__
    add_image(NULL, image_data[i]);
#else
    delete image_data[i];
#endif
  }
}

void Fl_Abstract_Printer::add_image(Fl_Image *image, const uchar *data)
{
  struct chain_elt *elt =  (struct chain_elt *)calloc(sizeof(struct chain_elt), 1);
  elt->image = image;
  elt->data = data;
  if (image_list_) { elt->next = image_list_; }
  image_list_ = elt;
}

void Fl_Abstract_Printer::delete_image_list()
{
  while(image_list_) {
    struct chain_elt *next = image_list_->next;
    if(image_list_->image) delete image_list_->image;
    if (image_list_->data) delete (uchar*) image_list_->data; // msvc6 compilation fix
    free(image_list_);
    image_list_ = next;
  }
}

Fl_Device *Fl_Abstract_Printer::set_current(void)
{
#ifdef __APPLE__
  fl_gc = (CGContextRef)gc;
#elif defined(WIN32)
  fl_gc = (HDC)gc;
#else
  fl_gc = (_XGC*)gc;
#endif
  return this->Fl_Device::set_current();
}


int Fl_Abstract_Printer::start_job(int pagecount, int *frompage, int *topage) {return 1;}
int Fl_Abstract_Printer::start_page (void) {return 1;}
int Fl_Abstract_Printer::printable_rect(int *w, int *h) {return 1;}
void Fl_Abstract_Printer::margins(int *left, int *top, int *right, int *bottom) {}
void Fl_Abstract_Printer::origin(int x, int y) {}
void Fl_Abstract_Printer::scale (float scale_x, float scale_y) {}
void Fl_Abstract_Printer::rotate(float angle) {}
int Fl_Abstract_Printer::end_page (void) {return 1;}
void Fl_Abstract_Printer::end_job (void) {}
void Fl_Abstract_Printer::translate(int x, int y) {}
void Fl_Abstract_Printer::untranslate(void) {}

Fl_Device *Fl_Device::set_current(void)
{
  Fl_Device *current = fl_device;
  fl_device = this;
  return current;
}

Fl_Device *Fl_Device::current(void)
{
  return fl_device;
}

//
// End of "$Id$".
//
