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
	m1->position = { 1.0f, 1.0f };
	m1->setSize(10.0f, 10.0f, 40.0f);
	m1->setRemanence(1.3f);

	sceneObjects.push_back(std::move(m1));

	auto m2 = std::make_unique<magnet>();
	m2->position = { 0.0f, 0.0f };
	m2->setSize(10.0f, 10.0f, 40.0f);
	m2->setRemanence(2.6f);

	sceneObjects.push_back(std::move(m2));

	auto m3 = std::make_unique<magnet>();
	m3->position = { -3.0f, -2.0f };
	m3->setSize(10.0f, 10.0f, 40.0f);
	m3->setRemanence(10.0f);

	sceneObjects.push_back(std::move(m3));

	
	
	while (!WindowShouldClose()) {
		drawFrame();
	}
	CloseWindow();

	return 0;
}
