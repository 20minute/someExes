#ifndef PHYS_VECTOR3D
#define PHYS_VECTOR3D


namespace phys
{
	/**
	 * @brief A 3D-space vector of 3 components (X, Y, Z) with floating point precision.
	 */
	class Vector3D
	{
	public:
		/**
		 * @brief Default constructor. Initializes components with zero.
		 */
		Vector3D();

		/**
		 * @brief Construct a new Vector3D object and initializing all components to a single float value.
		 *
		 * @param f Value to set all components to.
		 */
		Vector3D(float f);

		/**
		 * @brief Construct a new Vector3D object using initial values for each component.
		 *
		 * @param x X component.
		 * @param y Y component.
		 * @param z Z component.
		 */
		Vector3D(float x, float y, float z);

		/**
		 * @brief Copy constructor
		 */
		Vector3D(const Vector3D& other);

		/**
		 * @brief Destroy the Vector3D object.
		 */
		~Vector3D();

		/**
		 * @brief Add a vector to this.
		 *
		 * @param other The vector to add to this.
		 */
		void Add(const Vector3D& other);

		/**
		 * @brief Gets the result of component-wise addition of this and another vector.
		 *
		 * @param other
		 * @return Vector3D
		 */
		Vector3D operator+(const Vector3D& other) const;

		/**
		 * @brief Adds another vector to this. Uses component-wise addition.
		 *
		 * @param other Vector to add to this.
		 */
		inline void operator+=(const Vector3D& other)
		{
			Add(other);
		}

		/**
		 * @brief Subtract a vector to this.
		 *
		 * @param other The vector to add to this.
		 */
		void Subtract(const Vector3D& other);

		/**
		 * @brief Gets the result of component-wise substraction of this and another vector.
		 *
		 * @param other
		 * @return Vector3D
		 */
		Vector3D operator-(const Vector3D& other) const;

		Vector3D operator-() const;

		/**
		 * @brief Subtract another vector to this. Uses component-wise addition.
		 *
		 * @param other Vector to add to this.
		 */
		inline void operator-=(const Vector3D& other)
		{
			Subtract(other);
		}

		/**
		 * @brief Scales the vector.
		 *
		 * @param scale Amount to scale this vector by.
		 */
		template<typename T>
		void Multiply(T scale)
		{
			m_x *= scale;
			m_y *= scale;
			m_z *= scale;
		}

		/**
		 * @brief Scales the vector.
		 *
		 * @param scale Amount to scale this vector by.
		 */
		template<typename T>
		void operator*=(T scale)
		{
			Multiply(scale);
		}

		/**
		 * @brief Multiplies the vector with another vector, using component-wise multiplication.
		 *
		 * @param other What to multiply this vector with.
		 */
		void Multiply(const Vector3D& other);


		/**
		 * @brief Gets the result of component-wise multiplication of this vector by another.
		 *
		 * @param other The vector to multiply with.
		 * @return Vector3D The result of multiplication.
		 */
		Vector3D Product(const Vector3D& other) const;

		/**
		 * @brief Gets the result of component-wise multiplication of this vector by another.
		 *
		 * @param other The vector to multiply with.
		 * @return Vector3D The result of multiplication.
		 */
		inline Vector3D operator*(const Vector3D& other) const
		{
			return Product(other);
		}

		/**
		 * @brief Multiplies the vector with another vector, using component-wise multiplication.
		 *
		 * @param other What to multiply this vector with.
		 */
		inline void operator*=(const Vector3D& other)
		{
			Multiply(other);
		}

		/**
		 * @brief Calculate the dot product of the vector with another vector.
		 *
		 * @param other The vector to dotproduct with.
		 * @return float The dot product.
		 */
		float DotProduct(const Vector3D& other) const;

		/**
		 * @brief Calculate the cross product of the vector with another vector.
		 *
		 * @param other The vector to crossproduct with.
		 * @return Vector3D The cross product.
		 */
		Vector3D CrossProduct(const Vector3D& other) const;

		/**
		 * @brief Divides the vector by a number.
		 *
		 * @param scale What to divide this vector by.
		 */
		void Divide(int scale);

		/**
		 * @brief Gets the result of dividing each component of the vector by a value.
		 *
		 * @param scale What to divide each component by.
		 * @return Vector3D The result of division.
		 */
		Vector3D operator/(int scale) const;

		/**
		 * @brief Divides the vector by a number.
		 *
		 * @param scale What to divide this vector by.
		 */
		void operator/=(int scale)
		{
			Divide(scale);
		}

		/**
		 * @brief Divides the vector by a number.
		 *
		 * @param scale What to divide this vector by.
		 */
		void Divide(float scale);

		/**
		 * @brief Gets the result of scaling the vector (multiplying each component by a value).
		 *
		 * @param scale What to multiply each component by.
		 * @return Vector3D The result of multiplication.
		 */
		Vector3D operator/(float scale) const;

		/**
		 * @brief Divides the vector by a number.
		 *
		 * @param scale What to divide this vector by.
		 */
		void operator/=(float scale)
		{
			Divide(scale);
		}

		/**
		 * @brief Divides the vector by another vector, using component-wise division.
		 *
		 * @param What to divide vector by.
		 */
		void Divide(const Vector3D& other);

		/**
		 * @brief Gets the result of component-wise division of this vector by another.
		 *
		 * @param other The vector to divide by.
		 * @return Vector3D The result of division.
		 */
		Vector3D operator/(const Vector3D& other) const;

		/**
		 * @brief Divides the vector by another vector, using component-wise division.
		 *
		 * @param What to divide vector by.
		 */
		inline void operator/=(const Vector3D& other)
		{
			Divide(other);
		}

		bool operator ==(const Vector3D& other) const;

		/**
		 * @brief Get the length (magnitude) of this vector.
		 *
		 * @return float The length of this vector.
		 */
		float Magnitude() const;

		/**
		 * @brief Get the squared length (magnitude) of this vector.
		 *
		 * @return float The squared length of this vector.
		 */
		float SqrMagnitude() const;

		/**
		 * @brief Check if the vector is unit length.
		 *
		 * @return true if the vector is a unit vector.
		 * @return false otherwise.
		 */
		bool IsUnit() const;

		/**
		 * @brief Euclidean distance between the vector and an another vector.
		 *
		 * @return float The distance between the two vectors.
		 */
		float Distance(const Vector3D& other) const;

		/**
		 * @brief Makes this vector have a magnitude of 1.
		 */
		void Normalize();

		/**
		 * @brief Returns this vector with a magnitude of 1.
		 *
		 * Note that the current vector is unchanged and a new normalized vector is returned.
		 */
		Vector3D Normalized() const;

		/**
		* @brief Returns a world vector.
		*
		* @param v the current vector is a local one.
		*/
		Vector3D localToWorld(const Vector3D& v) const;

		/**
		* @brief Returns a local vector.
		*
		* @param v the current vector is a world one.
		*/
		Vector3D worldToLocal(const Vector3D& v) const;

		inline float X() const
		{
			return m_x;
		}

		inline float Y() const
		{
			return m_y;
		}

		inline void SetY(float y)
		{
			m_y = y;
		}

		inline float Z() const
		{
			return m_z;
		}

		static const Vector3D AXIS_X;

		static const Vector3D AXIS_Y;

		static const Vector3D AXIS_Z;

		static const Vector3D NEGATIVE_AXIS_X;

		static const Vector3D NEGATIVE_AXIS_Y;

		static const Vector3D NEGATIVE_AXIS_Z;

	private:
		/**
		 * @brief X component.
		 */
		float m_x;
		/**
		 * @brief Y component.
		 */
		float m_y;
		/**
		 * @brief Z component.
		 */
		float m_z;
	};

	/**
	 * @relates Vector3D
	 *
	 * @brief Gets the result of scaling the vector (multiplying each component by a value).
	 *
	 * @param vec The vector to multiply.
	 * @param scale What to multiply each component by.
	 * @return Vector3D The result of multiplication.
	 */
	template<typename T>
	Vector3D operator*(T scale, const Vector3D& vec)
	{
		Vector3D result(vec);
		result.Multiply(scale);
		return result;
	}

	/**
	 * @relates Vector3D
	 *
	 * @brief Gets the result of scaling the vector (multiplying each component by a value).
	 *
	 * @param vec The vector to multiply.
	 * @param scale What to multiply each component by.
	 * @return Vector3D The result of multiplication.
	 */
	template<typename T>
	Vector3D operator*(const Vector3D& vec, T scale)
	{
		Vector3D result(vec);
		result.Multiply(scale);
		return result;
	}

}

#endif // PHYS_VECTOR3D
