#pragma once

/*!
 * \file LgSwitch.h
 * \brief File containing the class for data representing a button
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGSWITCH_H_
#define LGSWITCH_H_

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{
	/*!
	 * \brief Class for representing data (button)
	 * A Switch represents a type of button with 2 states : pressed and released
	 * Switch is used parallely to 3D, 2D and 1D data in the data flow
	*/
	class Switch
	{
	protected:
		//! State (false = released / true = pressed) of the Switch
		bool _state;
	public:
		/*!
		 * \brief Default constructor
		 */
		Switch(void);

		/*!
		 * \brief Constructor with initial state
		 * \param[in] state : the state to give to the Switch
		 */
		Switch(bool state);

		/*!
		 * \brief Constructor by copy, copy the state from another Switch
		 * \param[in] copy : another Switch from which copy the value
		 */
		Switch(const Switch &copy);

		/*!
		 * \brief Destructor
		 */
		~Switch(void);

		/*!
		 * \brief Get the current state of the Switch
		 * \return The state of this Switch
		 */
		bool getState() const { return _state;}

		/*!
		 * \brief Is the current Switch pressed
		 * \return true if the Switch is pressed
		 */
		bool isPressed() const {return (_state == true);}

		/*!
		 * \brief Is the current Switch released
		 * \return true if the Switch is released
		 */
		bool isReleased() const {return (_state == false);}
	};

}

#endif /* LGSWITCH_H_ */