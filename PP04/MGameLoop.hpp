#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point time;


	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{

		}
		void Release()
		{
		}

		void Input()
		{
			/*	if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{

				}
				else
				{

				}*/
			time = chrono::system_clock::now();
		}
		void Update()
		{

		}
		void Render()
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();

			cRenderer.Clear();

			chrono::duration<double> EndDuration = chrono::system_clock::now() - time;
			EndDuration *= 3000;

			cout << " FPS(milliseconds) : " + to_string(int(EndDuration.count()));
		}



		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));




	};






}