#ifndef WL_GRID_H
#define WL_GRID_H

#include <vector>
#include "WindowLib.hpp"

namespace WindowLib
{
	class Grid
	{
		public:
		
			Grid()
			{
			
			}
			
			int ChildrenCount()
			{
				return ButtonContent.size();
			}
			
			std::vector<WindowLib::Button> GetChildren()
			{
				return ButtonContent;
			}
			
			WindowLib::Button GetChildAt(int _index)
			{
				return ButtonContent[_index];
			}
			
			void AddChild(WindowLib::Button _child)
			{
				ButtonContent.push_back(_child);
			}
			
			void Clear()
			{
				ButtonContent.clear();
			}
			
		private:
			
			std::vector<WindowLib::Button> ButtonContent;
	};
};

#endif
