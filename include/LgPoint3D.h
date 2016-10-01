#pragma once

/*!
 * \file LgPoint3D.h
 * \brief File containing the Point3D class, which represents a 3D coordinate.
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
	 * \class Point3D
	 * \brief Class for storing a 3D coordinate (position or orientation).
	*/
	class Point3D
	{
	private:
		//! First axis
		float _X;

		//! Second axis
		float _Y;

		//! Third axis
		float _Z;

	public:
		/*!
		 * \brief Default constructor, assigning 0 values on all axis 
		 */
		Point3D(): _X(0.0),_Y(0.0),_Z(0.0){};

		/*!
		 * \brief Constructor by copy, copy coordinates from another Point3D
		 * \param[in] copy : another Point3D from which copy the values
		 */
		Point3D(const Point3D& copy): _X(copy.getX()),_Y(copy.getY()),_Z(copy.getZ()){};
		
		/*!
		 * \brief Constructor with values, assigning corresponding values on each axis
		 * \param[in] x : value for the first axis
		 * \param[in] y : value for the second axis
		 * \param[in] z : value for the third axis
		 */
		Point3D(float x,float y, float z): _X(x),_Y(y),_Z(z){};

		/*!
		 * \brief Destructor
		 */
		~Point3D(void){};

		/*!
		 * \brief Informs if all values on every axis are null
		 * \return true if all values are null, false in other cases
		 */
		inline bool isNul(){return ((_X==0.0)&&(_Y==0.0)&&(_Z==0.0));}

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
		 * \brief Get the value of the third axis
		 * \return The value related to the third axis
		 */
		inline float getZ() const {return _Z;}

		/*!
		 * \brief Set the value for the third axis
		 * \param[in] z : the new value to link with the third axis
		 */
		inline void setZ(float z){_Z = z;}

		/*!
		 * \brief This function indicates whether the Point3D in parameter is equal to the current one
		 * Equality between Point3D is an equality of every values of each axis
		 * \param[in] other : the Point3D to compare to the current one
		 * \return true if values on each axis are equal of the value on the same axis of the other Point3D
		 */
		bool operator==(const Point3D other){return ((_X == other.getX())&&(_Y == other.getY())&&(_Z == other.getZ()));}

		/*!
		 * \brief Computes the distance between a given Point3D and the current one
		 * \param[in] p3D : another Point3D from which computes distance
		 * \return The distance between the given Point3D and the current one (always positive)
		 */
		inline float distanceTo(const Point3D &p3D) const
		{ Point3D tmp = Point3D(_X-p3D.getX(), _Y-p3D.getY(), _Z-p3D.getZ());
		   return (float)sqrt(tmp.getX()*tmp.getX()+tmp.getY()*tmp.getY()+tmp.getZ()*tmp.getZ());}

	};

	/*!
	* \brief A structure for storing a 3D orientation
	* Orientation is different from position because it stores angles (in radians or degrees)
	*/
	typedef Point3D Orientation3D;
}