;// MagneticSandbox.cpp : Defines the entry point for the application.
//

#include "MagneticSandbox.h"
#include "raylib.h"
#include "UI/viewport/viewport.h"
#include "magnet/magnet.h"

using namespace std;

int main()
{
	cout << "This is the Magnetic Sandbox Simulator by Martin Šafrata, 2026/27" << endl;
	bool initOk = initViewport();
	cout<< "Viewport initialized? " << initOk << endl;

	auto m1 = std::make_unique<magnet>();
	m1->position = { 0.0f, 0.0f };
	m1->setSize(1000.0f, 1000.0f, 4000.0f);

	sceneObjects.push_back(std::move(m1));
	res.load();

	
	
	while (!WindowShouldClose()) {
		drawFrame();
	}
	CloseWindow();

	return 0;
}
