#ifndef WL_WINDOW_H
#define WL_WINDOW_H

#include <gtk/gtk.h>
#include "WindowLib.hpp"

namespace WindowLib
{
	class Window : public WindowLib::UIObject
	{
		public:
			
			Window(int _width, int _length) : 
			WindowLib::UIObject(WindowLib::UIWindow, _width, _length)
			{
				title = "Window";
				//grid = Grid();
			}		
			
			void InitializeComponents()
			{
				widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
				fixed = gtk_fixed_new();
				gtk_window_set_title(GTK_WINDOW(widget), title.c_str());
				gtk_window_set_default_size(GTK_WINDOW(widget), this->GetWidth(), 
					this->GetLength());
				gtk_window_set_position(GTK_WINDOW(widget), GTK_WIN_POS_CENTER);
				gtk_container_add(GTK_CONTAINER(widget), fixed);
				g_signal_connect(widget, "destroy", G_CALLBACK(gtk_main_quit), NULL);
				isInitialized = true;
			}
			
			
			void SetTitle(std::string _title)
			{
				title = _title;
			}
			
			std::string GetTitle()
			{
				return title;
			}
			
			GtkWidget* GetGrid()
			{
				return fixed;
			}
			
			GtkWidget* GetWidget()
			{
				return widget;
			}
			
			void ShowContent()
			{
				if(isInitialized)
				{
					gtk_widget_show_all (widget);
					gtk_main();
				}
			}
			
			void CloseContent()
			{
				g_signal_connect(widget, "destroy", G_CALLBACK(gtk_main_quit), NULL);
			}
			
		private:
		
			GtkWidget *widget;
			GtkWidget *fixed;
			GtkApplication *app;
			std::string title = "";
			//WindowLib::Grid grid;
			bool isInitialized = false;
			
			/*
			void CreateChildren()
			{
				std::cout << "Started Creating Children\nCount: " << grid.ChildrenCount() << "\n";
				for(WindowLib::Button btn: grid.GetChildren())
				{
						std::cout << "Creating Button!\n";
						btn.CreateWidget(widget);
						std::cout << "Button Created!\n";
				}					
			}
			*/
	};
};

#endif
