#pragma once

#include <Windows.h>

namespace DCEngine {

	class Timer {
	private:
		LARGE_INTEGER m_start;
		double m_Frequency;

	public:
		Timer() {
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_Frequency = 1.0 /frequency.QuadPart;
			QueryPerformanceCounter(&m_start);
		}

		void reset() {
			QueryPerformanceCounter(&m_start);
		}

		float elapsed() {
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned _int64 cycles = current.QuadPart - m_start.QuadPart;
			return (float)(cycles * m_Frequency);
		}
	};
}