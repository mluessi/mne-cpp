//=============================================================================================================
/**
* @file     sourceestimate.h
* @author   Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     July, 2012
*
* @section  LICENSE
*
* Copyright (C) 2012, Christoph Dinh and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of the Massachusetts General Hospital nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MASSACHUSETTS GENERAL HOSPITAL BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief     SourceEstimate class declaration.
*
*/

#ifndef SOURCEESTIMATE_H
#define SOURCEESTIMATE_H

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "inverse_global.h"


//*************************************************************************************************************
//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================

#include <Eigen/Core>


//*************************************************************************************************************
//=============================================================================================================
// Qt INCLUDES
//=============================================================================================================

#include <QList>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE INVERSELIB
//=============================================================================================================

namespace INVERSELIB
{


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace Eigen;


//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================



//=============================================================================================================
/**
* Source estimation which holds results of MNE-CPP inverse routines
*
* @brief Source estimation
*/
class INVERSESHARED_EXPORT SourceEstimate
{
public:

    //=========================================================================================================
    /**
    * Default constructor
    */
    SourceEstimate();

    //=========================================================================================================
    /**
    * Constructs a source estimation from given data
    *
    * @param[in] p_sol
    * @param[in] p_vertices
    * @param[in] p_tmin
    * @param[in] p_tstep
    */
    SourceEstimate(const MatrixXd &p_sol, const QList<VectorXi> &p_vertices, float p_tmin, float p_tstep);

    //=========================================================================================================
    /**
    * Copy constructor.
    *
    * @param[in] p_SourceEstimate    Source estimate data which should be copied
    */
    SourceEstimate(const SourceEstimate& p_SourceEstimate);

    //=========================================================================================================
    /**
    * Initializes source estimate.
    */
    void clear();

    //=========================================================================================================
    /**
    * Returns whether SourceEstimate is empty.
    *
    * @return true if is empty, false otherwise
    */
    inline bool isEmpty();

public:
    MatrixXd data;          /**< Matrix of shape [n_dipoles x n_times] which contains the data in source space. */
    QList<VectorXi> vertno; /**< The indices of the dipoles in the different source spaces. */ //ToDo define is_clustered_result; change vertno to ROI idcs
    RowVectorXf times;      /**< The time vector with n_times steps. */
    float tmin;             /**< Time starting point. */
    float tstep;            /**< Time steps within the times vector. */

private:

    //=========================================================================================================
    /**
    * Update the times attribute after changing tmin, tmax, or tstep
    */
    void update_times();
};


//*************************************************************************************************************
//=============================================================================================================
// INLINE DEFINITIONS
//=============================================================================================================

inline bool SourceEstimate::isEmpty()
{
    return tstep == -1;
}

} //NAMESPACE

#endif // SOURCEESTIMATE_H
