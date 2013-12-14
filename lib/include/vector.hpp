#pragma once

#include <antitrivector.hpp>
#include <iostream>
#include <Eigen/Dense>
#include <base.hpp>

namespace gca {
	class GCA_scalar;
	class CommaTrick;
	
	class GCA_vector : public GCA_base {
	public:
		GCA_vector();
		GCA_vector(const GCA_vector& other);
		GCA_vector(double x, double y, double z, double w);


		void operator^(const GCA_vector& other);
		GCA_antitrivector operator~();

		CommaTrick operator<<(double d);
		friend class CommaTrick;

	private:

	};

	class CommaTrick {
	public:
		CommaTrick(GCA_vector& v, double d) :
			v(v), m_counter(0)
		{ insert(d); }

		CommaTrick& operator,(double d) {
			insert(d);
			return *this;
		}

		void insert(double d) {
			if(m_counter < 4)
				v.set(static_cast<Base>(m_counter++), d);
		}
	private:
		GCA_vector& v;
		int m_counter;
	};

	GCA_vector operator*(const GCA_vector& a, const GCA_scalar& b);
	GCA_vector operator*(const GCA_scalar& a, const GCA_scalar& b);
	

}