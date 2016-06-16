#ifndef WL_CONTROL_H
#define WL_CONTROL_H

#include "WindowLib.hpp"

namespace WindowLib
{
	enum ControlType
	{
		ControlButton,
		ControlTextBox,
		ControlLabel,
		ControlNull
	};
	
	class Control : public WindowLib::UIObject
	{
		public:
			
			Control(ControlType _cType, int _width, int _length, float _xPos, float _yPos) :
				WindowLib::UIObject(WindowLib::UIControl, _width, _length)
			{
				cType = _cType;
				xPos = _xPos;
				yPos = _yPos;
			}
			
			ControlType GetControlType()
			{
				return cType;
			}
			
			float GetX()
			{
				return xPos;
			}
			
			float GetY()
			{
				return yPos;
			}
			
			
			
		private:
			
			ControlType cType = ControlNull;
			float xPos = 0;
			float yPos = 0;		
	};
};

#endif
