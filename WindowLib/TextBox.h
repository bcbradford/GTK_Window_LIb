#ifndef WL_TEXTBOX_H
#define WL_TEXTBOX_H

#include <gtk/gtk.h>
#include "WindowLib.hpp"
#include <string>
#include <iostream>

namespace WindowLib
{
	class TextBox : public WindowLib::Control
	{
		
		public:
			
			TextBox(std::string _name, int _xPos, int _yPos) : 
				Control(WindowLib::ControlTextBox, 50, 50, _xPos, _yPos)
			{
				tbName = _name;
			}
			
			std::string GetName()
			{
				return tbName;
			}
			
			std::string GetText()
			{
				return gtk_entry_get_text(GTK_ENTRY(widget));
			} 
			
			void CreateWidget(GtkWidget *_windowGrid)
			{
				GtkWidget *vbox;
				vbox = gtk_vbox_new(FALSE, 0);
				widget = gtk_entry_new();
				gtk_widget_set_size_request(widget, this->GetLength(), this->GetWidth());
				gtk_fixed_put(GTK_FIXED(_windowGrid), vbox, this->GetX(), this->GetY());
				gtk_box_pack_start(GTK_BOX (vbox), widget, TRUE, TRUE, 0);
			}
			
		private:
		
			GtkWidget *widget;
			std::string tbName = "";
	
	};
	
};


#endif
