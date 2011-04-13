/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Joanna Stocka
 * Copyright (C) 2007-2011 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#include "lib/config.h"

#ifndef MULTIQUADRIC_H_
#define MULTIQUADRIC_H_

#include "lib/common.h"
#include "kernel/Kernel.h"
#include "distance/Distance.h"

namespace shogun
{

class CDistance;
/**
* MultiquadricKernel;
*f[
*             K(x,x') = \sqrt{\| x - x' \|^2 +c^2}
*\f]
*/
class CMultiquadricKernel: public CKernel
{
public:
	/** default constructor */
	CMultiquadricKernel();

	/** constructor
	 * @param cache size of cache
	 * @param coef kernel parameter coef
	 * @param dist distance to be used
	 */
	CMultiquadricKernel(int32_t cache, float64_t coef, CDistance* dist);

	/** constructor
	 * @param l features left-side
	 * @param r features right-side
	 * @param coef kernel parameter coef
	 * @param dist distance to be used
	 */
	CMultiquadricKernel(CFeatures *l, CFeatures *r, float64_t coef, CDistance* dist);

	/** initialize kernel with features
	 * @param l features left-side
	 * @param r features right-side
	 * @return true if successful
	 */
	virtual bool init(CFeatures* l, CFeatures* r);

	/**
	 * @return kernel type
	 */
	inline virtual EKernelType get_kernel_type() { return K_MULTIQUADRIC; }

	/**
	 * @return type of features
	 */
	inline virtual EFeatureType get_feature_type() { return distance->get_feature_type(); }

	/**
	 * @return class of features
	 */
	inline virtual EFeatureClass get_feature_class() { return distance->get_feature_class(); }

	/**
	 * @return name of kernel
	 */
	inline virtual const char* get_name() const { return "Multiquadric"; }

	/** getter for coef parameter
	 *  @return kernel parameter coefficient
	 */
	inline float64_t get_coef() { return this->coef; }

	/** setter for coef parameter
	 *  @param value kernel parameter coefficient
	 */
	inline void set_coef(float64_t value) { this->coef = value; }

	virtual ~CMultiquadricKernel();
protected:

	/// distance to be used
	CDistance* distance;

	/// theta parameter of kernel - coefficient
	float64_t coef;

	/**
	 * compute kernel for specific feature vectors
	 * corresponding to [idx_a] of left-side and [idx_b] of right-side
	 * @param idx_a left-side index
	 * @param idx_b right-side index
	 * @return kernel value
	 */
	virtual float64_t compute(int32_t idx_a, int32_t idx_b);

private:
	void init();
};
}

#endif /* MULTIQUADRIC_H_ */
