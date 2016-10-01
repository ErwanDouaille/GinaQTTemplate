#pragma once

/*!
 * \file LgPoint2D.h
 * \brief File containing the Point2D class, which represents a 2D coordinate.
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#include <math.h>

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
	{

	/*!
	 * \class Point2D
	 * \brief Class for storing a 2D coordinate.
	*/
	class Point2D
	{
	private:
		//! First axis
		float _X;

		//! Second axis
		float _Y;

	public:
		/*!
		 * \brief Default constructor, assigning 0 values on all axis 
		 */
		Point2D(): _X(0.0),_Y(0.0){};

		/*!
		 * \brief Constructor by copy, copy coordinates from another Point2D
		 * \param[in] copy : another Point2D from which copy the values
		 */
		Point2D(const Point2D& copy): _X(copy.getX()),_Y(copy.getY()){};

		/*!
		 * \brief Constructor with values, assigning corresponding values on each axis
		 * \param[in] x : value for the first axis
		 * \param[in] y : value for the second axis
		 */
		Point2D(float x,float y): _X(x),_Y(y){};

		/*!
		 * \brief Destructor
		 */
		~Point2D(void){};

		/*!
		 * \brief Informs if all values on every axis are null
		 * \return true if all values are null, false in other cases
		 */
		inline bool isNul(){return ((_X==0.0)&&(_Y==0.0));}

		/*!
		 * \brief This function indicates whether the Point2D in parameter is equal to the current one
		 * Equality between Point2D is an equality of every values of each axis
		 * \param[in] other : the Point2D to compare to the current one
		 * \return true if values on each axis are equal of the value on the same axis of the other Point2D
		 */
		bool operator==(const Point2D other){return ((_X == other.getX())&&(_Y == other.getY()));}

		/*!
		 * \brief Get the value of the first axis
		 * \return The value related to the first axis
		 */
		inline float getX() const {return _X;}

		/*!
		 * \brief Set the value for the first axis
		 * \param[in] x : the new value to link with the first axis
		 */
		inline void setX(float x){_X = x;}

		/*!
		 * \brief Get the value of the second axis
		 * \return The value related to the second axis
		 */
		inline float getY() const {return _Y;}

		/*!
		 * \brief Set the value for the second axis
		 * \param[in] y : the new value to link with the second axis
		 */
		inline void setY(float y){_Y = y;}

		/*!
		 * \brief Computes the distance between a given Point2D and the current one
		 * \param[in] p2D : another Point2D from which computes distance
		 * \return The distance between the given Point2D and the current one (always positive)
		 */
		inline float distanceTo(const Point2D &p2D) const
		{ Point2D tmp = Point2D(_X-p2D.getX(), _Y-p2D.getY());
		   return (float)sqrt(tmp.getX()*tmp.getX()+tmp.getY()*tmp.getY());}

	};
}