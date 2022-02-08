///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           StringExtractor.cpp                                  
//
//  Facility:                                                                
//                                                                           
//                                                                           
//  Abstract:                                                                
//                                                                           
//  Environment:    VC 6.0                                                   
//                                                                           
//  Author:         Зайцев С. А.                                                          
//                                                                           
//  Creation Date:  29/03/2003                                  
//                                                                           
///////////////////////////////////////////////////////////////////////////////

#include "StringExtractor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CStringExtractor::CStringExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CStringExtractor::CStringExtractor (StringsStorage *pStorage/* = NULL*/,
                                    ITokenExtractor *pExtractor/* = NULL*/)
{
    SetStorage (pStorage);
    SetSpacesExtractor (pExtractor);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CStringExtractor::~CStringExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CStringExtractor::~CStringExtractor ()
{

}

///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CStringExtractor::GetStorage                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const CStringExtractor::StringsStorage& CStringExtractor::GetStorage () const
{
    return m_Storage;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CStringExtractor::SetStorage                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CStringExtractor::SetStorage (const CStringExtractor::StringsStorage *pStorage)
{
    if (NULL == pStorage)
        m_Storage.resize (0);
    else m_Storage = *pStorage;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CStringExtractor::GetSpacesExtractor
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

ITokenExtractor* CStringExtractor::GetSpacesExtractor () const
{
    return m_pCommonSpaceExtractor;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CStringExtractor::SetSpacesExtractor
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CStringExtractor::SetSpacesExtractor (ITokenExtractor *pExtractor)
{
    m_pCommonSpaceExtractor = pExtractor;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CStringExtractor::ExtractToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CStringExtractor::ExtractToken (const char* szData, 
                                            std::string &strToken, 
                                            eCommentState &eState)
{
    int nSize = m_Storage.size ();
    for (int nIdx = 0; nIdx < nSize; ++nIdx)
    {
        std::string &strTemplate = m_Storage [nIdx];
        int nLen = strTemplate.length ();
        if (strncmp (szData, strTemplate.c_str (), nLen) != 0)
            continue;
        
        const char *szNewPos = szData + nLen;
        if (m_pCommonSpaceExtractor != NULL)
        {
            const char *szNewPos = szData + nLen;
            std::string strTmp;
            if (*szNewPos != 0 &&
                m_pCommonSpaceExtractor->ExtractToken (szNewPos,
                                                       strTmp,
                                                       eState) == szNewPos)
                continue;
        }

        strToken = strTemplate;
        return szNewPos;        
    }
    
    strToken.resize (0);

    return szData;
}