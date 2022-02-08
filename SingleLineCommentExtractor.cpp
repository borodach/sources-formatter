///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           SingleLineCommentExtractor.cpp                                  
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


#include "SingleLineCommentExtractor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CSingleLineCommentExtractor::CSingleLineCommentExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CSingleLineCommentExtractor::CSingleLineCommentExtractor (const char *szBeginComment /*= NULL*/)
{
    SetBeginComment (szBeginComment);
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CSingleLineCommentExtractor::~CSingleLineCommentExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CSingleLineCommentExtractor::~CSingleLineCommentExtractor ()
{

}

///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CSingleLineCommentExtractor::GetBeginComment                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CSingleLineCommentExtractor::GetBeginComment () const
{
    return m_strBeginComment.c_str ();
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CSingleLineCommentExtractor::SetBeginComment                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CSingleLineCommentExtractor::SetBeginComment (const char* szMarker)
{
    if (NULL == szMarker)
        m_strBeginComment.resize (0);
    else m_strBeginComment = szMarker;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CSingleLineCommentExtractor::ExtractToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CSingleLineCommentExtractor::ExtractToken (const char* szData, 
                                                       std::string &strToken, 
                                                       eCommentState &eState)
{
    strToken.resize (0);
    int nBeginCommentLen = m_strBeginComment.length ();
 
    if (strncmp (szData, m_strBeginComment.c_str (), nBeginCommentLen) != 0)
    {
        return szData;
    }
    
    strToken = szData;
    return szData + strlen (szData);
}