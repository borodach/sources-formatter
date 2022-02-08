///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           CharExtractor.cpp                                  
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


#include "CharExtractor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCharExtractor::CCharExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CCharExtractor::CCharExtractor (const char *szTemplate/*= NULL*/)
{
    SetTemplate (szTemplate);
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCharExtractor::~CCharExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CCharExtractor::~CCharExtractor ()
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCharExtractor::GetTemplate                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CCharExtractor::GetTemplate () const
{
    return m_strTemplate.c_str ();
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCharExtractor::SetTemplate                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CCharExtractor::SetTemplate (const char *szTemplate)
{
    if (szTemplate != NULL)
        m_strTemplate = szTemplate;
    else m_strTemplate.resize (0);
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCharExtractor::ExtractToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CCharExtractor::ExtractToken (const char* szData, 
                                          std::string &strToken, 
                                          eCommentState &eState)
{
    strToken.resize (0);
    if (*szData == 0)
        return szData;
    char *pChar = strchr (m_strTemplate.c_str (), *szData);
    if (NULL == pChar)
        return szData;

    strToken = *pChar;

    return szData + 1;
}