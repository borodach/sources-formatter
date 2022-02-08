// SpaceExtractor.cpp: implementation of the CSpaceExtractor class.
//
//////////////////////////////////////////////////////////////////////

#include "SpaceExtractor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CSpaceExtractor::CSpaceExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CSpaceExtractor::CSpaceExtractor (const char *strTemplate/* = NULL*/):
CCharExtractor (strTemplate)
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CSpaceExtractor::~CSpaceExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CSpaceExtractor::~CSpaceExtractor ()
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CSpaceExtractor::ExtractToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CSpaceExtractor::ExtractToken (const char* szData, 
                                          std::string &strToken, 
                                          eCommentState &eState)
{
    strToken.resize (0);
    std::string strTmpToken;
    const char *szCurrentPos = szData;

    do
    {
        const char * szNewPos = CCharExtractor::ExtractToken (szCurrentPos, 
                                                              strTmpToken, 
                                                              eState);
        if (szNewPos == szCurrentPos) 
            break;
        strToken += strTmpToken;
        szCurrentPos = szNewPos;
    }
    while (1);
  
    return szCurrentPos;
}
