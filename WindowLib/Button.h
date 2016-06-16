#ifndef WL_BUTTON_H
#define WL_BUTTON_H

#include <gtk/gtk.h>
#include <functional>
#include "WindowLib.hpp"
#include <iostream>
#include <vector>

namespace WindowLib
{

	struct ClickEvent
	{
		public:
			
			std::string buttonName = "";
			std::string deviceUID = "";
			
			std::function<void(WindowLib::ClickEvent)> eventFunction;
					
			std::vector<WindowLib::Control*> controls;
			
			void operator()()
			{
				eventFunction(*this);
			}
	};

	static void Click(GtkButton *_button, gpointer _event)
	{	
		WindowLib::ClickEvent clickEvent = *static_cast<ClickEvent*>(_event);
		clickEvent();
	}
	
	GtkWidget *container;
	
	class Button : public WindowLib::Control
	{
		public:
			
			Button(std::string _name, std::string _label, float _xPos, float _yPos) :
				WindowLib::Control(WindowLib::ControlButton, 75, 30, _xPos, _yPos)
			{
				buttonName = _name;
				buttonLabel = _label;
				event.buttonName = _name;
			}
			
			void CreateWidget(GtkWidget *_windowGrid,
			std::vector<WindowLib::ClickEvent*> *_eventVector)
			{	
				buttonWidget = gtk_button_new_with_label (buttonLabel.c_str());
				
				// Set Click Event Handler
				WindowLib::ClickEvent *clickEvent = CreateClickEvent();
				g_signal_connect (buttonWidget, "clicked", G_CALLBACK (Click), clickEvent);
				
				gtk_widget_set_size_request(buttonWidget, this->GetWidth(), this->GetLength());
				gtk_fixed_put(GTK_FIXED(_windowGrid), buttonWidget, this->GetX(), this->GetY());
				_eventVector->push_back(clickEvent);
			}
			
			std::string GetLabel()
			{
				return buttonLabel;
			}
			
			void SetLabel(std::string _label)
			{
				buttonLabel = _label;
			}
			
			GtkWidget* GetWidget()
			{
				return buttonWidget;
			}
			
			void SetClickEvent(std::function<void(WindowLib::ClickEvent)> _function,
			std::vector<WindowLib::Control*> *vec)
			{
				event.eventFunction = _function;
				event.controls = *vec;
			}
			
		private:
		
			GtkWidget *buttonWidget;
			std::string buttonName = "";
			std::string buttonLabel = "";
			WindowLib::ClickEvent event;
			
			ClickEvent* CreateClickEvent()
			{
				WindowLib::ClickEvent *clickEvent = new ClickEvent();
				clickEvent->buttonName = event.buttonName;
				clickEvent->eventFunction = event.eventFunction;
				clickEvent->deviceUID = event.deviceUID;
				clickEvent->controls = event.controls;
				return clickEvent;
			}
	};
};

#endif
