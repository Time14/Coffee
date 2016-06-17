#ifndef __BEAN__H__
#define __BEAN__H__


#include "include.h"
#include "inputmanager.h"
#include "display.h"
#include "component.h"
#include "graphicscomponent.h"

#include <vector>

namespace coffee {

	class Bean {
	public:
		Bean();
		~Bean();

		void brew();

		static void registerComponentManagerFunction(void(*function)(float));

		static void stop();

	private:


		static std::vector<void(*)(float)> _functions;
		static bool _running;

		Display _display;

	};
}

#endif // !__BEAN__H__