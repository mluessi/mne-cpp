//=============================================================================================================
/**
* @file     IMeasurementSource.cpp
* @author   Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     February, 2013
*
* @section  LICENSE
*
* Copyright (C) 2013, Christoph Dinh and Matti Hamalainen. All rights reserved.
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
* @brief    Contains the implementation of the IMeasurementSource interface.
*
*/

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "IMeasurementSource.h"
#include "numeric.h"
#include "realtimesamplearray.h"
#include "realtimemultisamplearray.h"
#include "realtimemultisamplearray_new.h"
#include "realtimesourceestimate.h"
#include "progressbar.h"
#include "text.h"
//#include "alert.h"


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace XMEASLIB;


//*************************************************************************************************************
//=============================================================================================================
// DEFINE MEMBER METHODS
//=============================================================================================================

IMeasurementSource::~IMeasurementSource()
{

}


//*************************************************************************************************************

QSharedPointer<Numeric> IMeasurementSource::addProviderNumeric(MSR_ID::Measurement_ID id)
{
    //ToDo Check if belongs to group (division with group id)
    // if id already exists push warning and return the existing channel Todo Todo
    QSharedPointer<Numeric> num = QSharedPointer<Numeric>(new Numeric);
    num->setID(id);
    //num->setModuleID(m_MDL_ID);
    m_hashNumeric.insert(id, num);
    return num;
}


//*************************************************************************************************************

QSharedPointer<RealTimeSampleArray> IMeasurementSource::addProviderRealTimeSampleArray(MSR_ID::Measurement_ID id)
{
    QSharedPointer<RealTimeSampleArray> rtsa = QSharedPointer<RealTimeSampleArray>(new RealTimeSampleArray);
    rtsa->setID(id);
    //rtsa->setModuleID(m_MDL_ID);
    m_hashRealTimeSampleArray.insert(id, rtsa);
    return rtsa;
}

//*************************************************************************************************************

QSharedPointer<RealTimeMultiSampleArray> IMeasurementSource::addProviderRealTimeMultiSampleArray(MSR_ID::Measurement_ID id, unsigned int uiNumChannels)
{
    QSharedPointer<RealTimeMultiSampleArray> rtmsa = QSharedPointer<RealTimeMultiSampleArray>(new RealTimeMultiSampleArray(uiNumChannels));
    rtmsa->setID(id);
    //rtsa->setModuleID(m_MDL_ID);
    m_hashRealTimeMultiSampleArray.insert(id, rtmsa);
    return rtmsa;
}


//*************************************************************************************************************

QSharedPointer<RealTimeMultiSampleArrayNew> IMeasurementSource::addProviderRealTimeMultiSampleArray_New(MSR_ID::Measurement_ID id)
{
    QSharedPointer<RealTimeMultiSampleArrayNew> rtmsa = QSharedPointer<RealTimeMultiSampleArrayNew>(new RealTimeMultiSampleArrayNew());
    rtmsa->setID(id);
    //rtsa->setModuleID(m_MDL_ID);
    m_hashRealTimeMultiSampleArrayNew.insert(id, rtmsa);
    return rtmsa;
}


//*************************************************************************************************************

QSharedPointer<RealTimeSourceEstimate> IMeasurementSource::addProviderRealTimeSourceEstimate(MSR_ID::Measurement_ID id)
{
    QSharedPointer<RealTimeSourceEstimate> rtse = QSharedPointer<RealTimeSourceEstimate>(new RealTimeSourceEstimate());
    rtse->setID(id);
    //rtsa->setModuleID(m_MDL_ID);
    m_hashRealTimeSourceEstimate.insert(id, rtse);
    return rtse;
}


//*************************************************************************************************************

QSharedPointer<ProgressBar> IMeasurementSource::addProviderProgressBar(MSR_ID::Measurement_ID id)
{
    QSharedPointer<ProgressBar> progress = QSharedPointer<ProgressBar>(new ProgressBar);
    progress->setID(id);
    //progress->setModuleID(m_MDL_ID);
    m_hashProgressBar.insert(id, progress);
    return progress;
}


//*************************************************************************************************************

QSharedPointer<Text> IMeasurementSource::addProviderText(MSR_ID::Measurement_ID id)
{
    QSharedPointer<Text> text = QSharedPointer<Text>(new Text);
    text->setID(id);
    //text->setModuleID(m_MDL_ID);
    m_hashText.insert(id, text);
    return text;
}


////*************************************************************************************************************
//
//Alert* IMeasurementSource::addProviderAlert(MSR_ID::Measurement_ID id)
//{
//    Alert* alert = new Alert;
//    alert->setID(id);
//    //alert->setModuleID(m_MDL_ID);
//    m_hashAlert.insert(id, alert);
//    return alert;
//}


//*************************************************************************************************************

QList<MSR_ID::Measurement_ID> IMeasurementSource::getProviderMeasurement_IDs() const
    {
    QList<MSR_ID::Measurement_ID> idList;
    idList << getProviderNumeric_IDs();
    idList << getProviderRTSA_IDs();
    idList << getProviderRTMSA_IDs();
    idList << getProviderRTMSA_New_IDs();
    idList << getProviderRTSE_IDs();
    idList << getProviderProgressbar_IDs();
    idList << getProviderText_IDs();
//    idList << getProviderAlert_IDs();

    return idList;
}


//*************************************************************************************************************

QList<MSR_ID::Measurement_ID> IMeasurementSource::getProviderNumeric_IDs() const
{
    QList<MSR_ID::Measurement_ID> idList;
    idList << m_hashNumeric.uniqueKeys();

    return idList;
}


//*************************************************************************************************************

QList<MSR_ID::Measurement_ID> IMeasurementSource::getProviderRTSA_IDs() const
{
    QList<MSR_ID::Measurement_ID> idList;
    idList << m_hashRealTimeSampleArray.uniqueKeys();

    return idList;
}


//*************************************************************************************************************

QList<MSR_ID::Measurement_ID> IMeasurementSource::getProviderRTMSA_IDs() const
{
    QList<MSR_ID::Measurement_ID> idList;
    idList << m_hashRealTimeMultiSampleArray.uniqueKeys();

    return idList;
}


//*************************************************************************************************************

QList<MSR_ID::Measurement_ID> IMeasurementSource::getProviderRTMSA_New_IDs() const
{
    QList<MSR_ID::Measurement_ID> idList;
    idList << m_hashRealTimeMultiSampleArrayNew.uniqueKeys();

    return idList;
}


//*************************************************************************************************************

QList<MSR_ID::Measurement_ID> IMeasurementSource::getProviderRTSE_IDs() const
{
    QList<MSR_ID::Measurement_ID> idList;
    idList << m_hashRealTimeSourceEstimate.uniqueKeys();

    return idList;
}


//*************************************************************************************************************

QList<MSR_ID::Measurement_ID> IMeasurementSource::getProviderProgressbar_IDs() const
{
    QList<MSR_ID::Measurement_ID> idList;
    idList << m_hashProgressBar.uniqueKeys();

    return idList;
}


//*************************************************************************************************************

QList<MSR_ID::Measurement_ID> IMeasurementSource::getProviderText_IDs() const
{
    QList<MSR_ID::Measurement_ID> idList;
    idList << m_hashText.uniqueKeys();

    return idList;
}


////*************************************************************************************************************
//
//QList<MSR_ID::Measurement_ID> IMeasurementSource::getProviderAlert_IDs() const
//{
//	QList<MSR_ID::Measurement_ID> idList;
//	idList << m_hashAlert.uniqueKeys();
//
//    return idList;
//}


//*************************************************************************************************************

void IMeasurementSource::cleanProvider()
{
//    foreach (Numeric* value, m_hashNumeric)
//            delete value;

//    foreach (RealTimeSampleArray* value, m_hashRealTimeSampleArray)
//            delete value;

//    foreach (RealTimeMultiSampleArray* value, m_hashRealTimeMultiSampleArray)
//            delete value;

//    foreach (RealTimeMultiSampleArrayNew* value, m_hashRealTimeMultiSampleArrayNew)
//            delete value;

//    foreach (RealTimeSourceEstimate* value, m_hashRealTimeSourceEstimate)
//            delete value;

//    foreach (ProgressBar* value, m_hashProgressBar)
//            delete value;

//    foreach (Text* value, m_hashText)
//            delete value;

//    foreach (Alert* value, m_hashAlert)
//            delete value;

    m_hashNumeric.clear();
    m_hashRealTimeSampleArray.clear();
    m_hashRealTimeMultiSampleArray.clear();
    m_hashRealTimeMultiSampleArrayNew.clear();
    m_hashRealTimeSourceEstimate.clear();
    m_hashProgressBar.clear();
    m_hashText.clear();
//    m_hashAlert.clear();
}
