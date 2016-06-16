#ifndef WL_MAINWINDOW_H
#define WL_MAINWINDOW_H

#include "WindowLib/WindowLib.hpp"
#include <iostream>
#include <functional>
#include <vector>

namespace WindowLib
{
	class MainWindow : public WindowLib::Window
	{	
		public:
		
			MainWindow() : WindowLib::Window(300, 150)
			{
				eventVector = new std::vector<ClickEvent*>();
				controlVector = new std::vector<WindowLib::Control*>();
				
				this->InitializeComponents();
				
				CreateTextBoxes();
				CreateButtons();
			}
			
			void Show()
			{
				this->ShowContent();
			}
			
			void Close()
			{
				this->CloseContent();
			}
			
			
			~MainWindow()
			{
				std::vector<WindowLib::ClickEvent*> vec = *eventVector;
				
				for(int i = 0; i < vec.size(); i++)
				{
					delete vec[i];
				}
				
				eventVector->clear();
				delete eventVector;
				
				std::vector<WindowLib::Control*> cVec = *controlVector;
				
				for(int i = 0; i < cVec.size(); i++)
				{
					delete cVec[i];
				}
				
				controlVector->clear();
				delete controlVector;
			}
			
			
		private:
			
			std::vector<WindowLib::ClickEvent*> *eventVector;
			std::vector<WindowLib::Control*> *controlVector;
			
			void CreateTextBoxes()
			{
				std::cout << "Creating Text Boxes\n";
				
				WindowLib::TextBox *tb = new WindowLib::TextBox("tb", 10, 0);
				WindowLib::TextBox *tb2 = new WindowLib::TextBox("tb2", 10, 50);
				WindowLib::TextBox *tb3 = new WindowLib::TextBox("tb3", 10, 100);
				
				tb->CreateWidget(this->GetGrid());
				tb2->CreateWidget(this->GetGrid());
				tb3->CreateWidget(this->GetGrid());
				
				controlVector->push_back(tb);
				controlVector->push_back(tb2);
				controlVector->push_back(tb3);
				
			}
			
			void CreateButtons()
			{
				std::cout << "Creating Buttons\n";
				
				WindowLib::Button *btn = new WindowLib::Button("btn1", "Button 1", 200, 10);
				WindowLib::Button *btn2 = new WindowLib::Button("btn2", "Button 2", 200, 60);
				WindowLib::Button *btn3 = new WindowLib::Button("btn3", "Button 3", 200, 110);
				
				controlVector->push_back(btn);
				controlVector->push_back(btn2);
				controlVector->push_back(btn3);
				
				btn2->SetClickEvent(GetText2, controlVector);
				btn->SetClickEvent(GetText1, controlVector);
				btn3->SetClickEvent(GetText3, controlVector);
				
				btn->CreateWidget(this->GetGrid(), eventVector);
				btn2->CreateWidget(this->GetGrid(), eventVector);
				btn3->CreateWidget(this->GetGrid(), eventVector);
			}
			
			static void Test(std::string test)
			{
				std::cout << test << "\n";
			}
			
			static void PrintHelloWorld()
			{
				std::cout << "Hello World!\n";
			}
			
			static void PrintHelloWorld2()
			{
				std::cout << "Hello World 2 Clicked!\n";
			}
			
			static void PrintHelloWorld3()
			{
				std::cout << "Hello World 3 Clicked!\n";
			}
			
			static void GetText1(WindowLib::ClickEvent event)
			{
				std::cout << "Button Name: " << event.buttonName << "\n";
					
				std::string name = "tb";
				WindowLib::TextBox tb = GetTextBox(name, event.controls); 
				std::string text = "";
				
				if(tb.GetName().compare("NULL") != 0)
				{
					text = tb.GetText();
				}

				std::cout << "Text Box 1 Text: " << text << "\n";
			}
			
			
			static void GetText2(WindowLib::ClickEvent event)
			{
				std::cout << "Button Name: " << event.buttonName << "\n";
				
				std::string name = "tb2";
				WindowLib::TextBox tb2 = GetTextBox(name, event.controls);
				std::string text = "";
				
				if(tb2.GetName().compare("NULL") != 0)
				{
					text = tb2.GetText();
				}
				
				std::cout << "Text Box 2 Text: " << text << "\n";
			}
			
			static void GetText3(WindowLib::ClickEvent event)
			{
				std::cout << "Button Name: " << event.buttonName << "\n";
			
				std::string name = "tb3";
				WindowLib::TextBox tb3 = GetTextBox(name, event.controls);
				std::string text = "";
				
				if(tb3.GetName().compare("NULL") != 0)
				{
					text = tb3.GetText();
				}
				
				std::cout << "Text Box 3 Text: " << text << "\n";
			}
			
			static WindowLib::TextBox GetTextBox(std::string _name,
			std::vector<WindowLib::Control*> vec)
			{
				for(WindowLib::Control *ctrl: vec)
				{
					if(ctrl->GetControlType() == ControlTextBox)
					{
						WindowLib::TextBox tb = *static_cast<WindowLib::TextBox*>(ctrl);
						std::cout << "Current TB Name: " << tb.GetName() << "\n";
						if(tb.GetName().compare(_name) == 0)
						{
							return tb;
						}
					} 
				}

				
				return WindowLib::TextBox("NULL", 0, 0);
			}
	};
};

#endif
