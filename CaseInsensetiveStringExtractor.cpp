///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           CaseInsensetiveStringExtractor.cpp                                  
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
//  Creation Date:  30/03/2003                                  
//                                                                           
///////////////////////////////////////////////////////////////////////////////

#include "CaseInsensetiveStringExtractor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCaseInsensetiveStringExtractor
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CCaseInsensetiveStringExtractor::CCaseInsensetiveStringExtractor (StringsStorage *pStorage/* = NULL*/,
                                                                 ITokenExtractor *pExtractor/* = NULL*/):
CStringExtractor (pStorage, pExtractor)
{
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       ~CCaseInsensetiveStringExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CCaseInsensetiveStringExtractor::~CCaseInsensetiveStringExtractor ()
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCaseInsensetiveStringExtractor::::ExtractToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CCaseInsensetiveStringExtractor::ExtractToken (const char* szData, 
                                                           std::string &strToken, 
                                                           eCommentState &eState)
{
    int nSize = m_Storage.size ();
    for (int nIdx = 0; nIdx < nSize; ++nIdx)
    {
        std::string &strTemplate = m_Storage [nIdx];
        int nLen = strTemplate.length ();
        if (strnicmp (szData, strTemplate.c_str (), nLen) != 0)
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