/**
 *
 * UIObject Class
 *
 * Brent Bradford - Created 2016/06/08
 *
 */
 
#ifndef GT_UIOBJECT_H
#define GT_UIOBJECT_H

#include <string>

namespace WindowLib
{

	enum ObjectType
	{
		UIControl,
		UIWindow,
		UINull
	};
	
	class UIObject
	{
		public:
			
			/**
			 * Constructor
			 * Brent Bradford 2016/06/08
			 */
			UIObject(ObjectType _type, int _width, int _length)
			{
				objType = _type;
				width = _width;
				length = _length;
			}
			
			/****** Getters **************************************/
			
			ObjectType GetObjectType()
			{
				return objType;
			}
			
			int GetWidth()
			{
				return width;
			}
			
			int GetLength()
			{
				return length;
			}
			
			/****** Setters **************************************/
			
			void SetWidth(int _width)
			{
				width = _width;
			}
			
			void SetLength(int _length)
			{
				length = _length;
			}
			
			std::string ObjectTypeToString()
			{
				if(objType == UIControl)
				{
					return "UIControl";
				}
				else if(objType == UIWindow)
				{
					return "UIWindow";
				}
				else
				{
					return "UINull";
				}
			}
			
		private:
			
			ObjectType objType = UINull;
			int width = 0;
			int length = 0;
			
	};
};

#endif
