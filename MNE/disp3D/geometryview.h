//=============================================================================================================
/**
* @file     geometryview.h
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
* @brief    Declaration of the GeometryView Class.
*
*/

#ifndef GEOMETRYVIEW_H
#define GEOMETRYVIEW_H

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "disp3D_global.h"


//*************************************************************************************************************
//=============================================================================================================
// MNE INCLUDES
//=============================================================================================================

#include <fs/annotation.h>
#include <mne/mne.h>


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include "qglview.h"
#include <QGeometryData>
#include <QGLColorMaterial>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE DISP3DLIB
//=============================================================================================================

namespace DISP3DLIB
{

//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace MNELIB;
using namespace FSLIB;


//QT_BEGIN_NAMESPACE
//class QGLSceneNode;
//QT_END_NAMESPACE

//=============================================================================================================
/**
* stereoscopic 3D geoemtry view
*
* @brief Geometry View
*/
class DISP3DSHARED_EXPORT GeometryView : public QGLView
{
    Q_OBJECT
public:

    //=========================================================================================================
    /**
    * Creates the geometry view.
    *
    * @param[in] parent     Parent QObject (optional)
    */
    GeometryView(QWindow *parent = 0);

    //=========================================================================================================
    /**
    * Destroys the geometry view.
    */
    ~GeometryView();

protected:
    //=========================================================================================================
    /**
    * Initializes the current GL context represented by painter.
    *
    * @param[in] painter    GL painter which should be initialized
    */
    void initializeGL(QGLPainter *painter);

    //=========================================================================================================
    /**
    * Paints the scene onto painter. The color and depth buffers will have already been cleared, and the camera() position set.
    *
    * @param[in] painter    GL painter which is updated
    */
    void paintGL(QGLPainter *painter);

private:
    MNEForwardSolution m_forwardSolution;   /**< Holds the forward soultion -> ToDo change this to shraed data pointer */

    bool m_bStereo;

    QGLLightModel *m_pLightModel;    /**< The selected light model. */
    QGLLightParameters *m_pLightParametersScene;    /**< The selected light parameters. */

    QGLColorMaterial material;

    QVector<Annotation::SPtr> m_vecAnnotation;

    QGLSceneNode *m_pSceneNodeBrain;               /**< Scene node of the hemisphere models. */
    QGLSceneNode *m_pSceneNode;                    /**< Node of the scene. */

//    QGLCamera *m_pCameraFrontal;     /**< frontal camera. */
};

} // NAMESPACE

#endif // GEOMETRYVIEW_H
