#pragma once

/*!
 * \file LgTimer.h
 * \brief File containing the Timer class, for managing the current time and computing the elapsed one
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGTIMER_H_
#define LGTIMER_H_

#if defined _WIN32  || defined _WIN64
#include "windows.h"
#else
#include <sys/time.h>
#if __APPLE__
#else
#endif
	#include <unistd.h>
#endif

#include <string>
#include <assert.h>

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{
	/*!
	 * \class Timer
	 * \brief Class for getting current time and computing frequency
	*/
	class Timer {
	private:
		//! Structures for getting and computing time

#if defined _WIN32  || defined _WIN64
		LARGE_INTEGER _startT, _lastT, _endT, _lastTfreq, _endTfreq, _lastTfreq2, _endTfreq2, _perffreq, _startTPause, _endTPause;
		__int64 _factor; // Depends on the type of Chrono: s, ms, micros
		__int64 _pauseTime;
#else
#if __APPLE__
#else
#endif
		struct timeval _startT, _lastT, _endT, _lastTfreq, _endTfreq, _lastTfreq2, _endTfreq2, _startTPause, _endTPause;
		long _factor; // Depends on the type of Chrono: s, ms, micros
		long _pauseTime;
		struct timezone _tz;
#endif


		//! State of the timer : 0=stop 1=play 2=pause
		int _state; 

	public:

		/*!
		 * \brief Default Constructor (must call init after the default constructor)
		 */
		Timer(void);

		/*!
		 * \brief Constructor with the type of timer
		 * \param[in] type : "s", "ms" or "micros"
		 */
		Timer(std::string type);

		/*!
		 * \brief Destructor
		 */
		~Timer(void);

		/*!
		 * \brief Initialize the timer for the specified type
		 * \param[in] type : "s", "ms" or "micros"
		 */
		void init(std::string type);

		/*!
		 * \brief Start the timer
		 */
		void start(void);

		/*!
		 * \brief Pause the timer
		 */
		void pause(void);
		
		/*!
		 * \brief Stop the timer
		 */
		void stop(void);
		
		/*!
		 * \brief Restart the timer
		 */
		void restart(void);

		/*!
		 * \brief Get the time from the start of the timer
		 * \return the time from the start
		 */
		int getTimeFromStart(void);

		/*!
		 * \brief Get time from the last request of the time
		 * \return The time from the last request of the time
		 */
		int getTimeFromLastMeasure(void);
		
		/*!
		 * \brief Get the frequency of the timer
		 * \return The frequency of the timer
		 */
		double getFreq(void);

		/*!
		 * \brief Set a frequency to the timer
		 * \param[in] freq : the new frequency to which update the timer
		 * \param[in] micosecondAccuracy : an accurracy to respect
		 * \return true if it is possible
		 */
		bool respectFreq(double freq, bool micosecondAccuracy);

	};
}

#endif // LGTIMER_H_
