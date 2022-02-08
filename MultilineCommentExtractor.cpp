///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           MultiLineCommentExtractor.cpp                                  
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


#include "MultiLineCommentExtractor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CMultiLineCommentExtractor::CMultiLineCommentExtractor
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CMultiLineCommentExtractor::CMultiLineCommentExtractor (const char *szBeginComment/* = NULL*/,
                                                        const char *szEndComment/* = NULL*/):
CSingleLineCommentExtractor (szBeginComment)
{
    SetEndComment (szEndComment);
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CMultiLineCommentExtractor::~CMultiLineCommentExtractor
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CMultiLineCommentExtractor::~CMultiLineCommentExtractor ()
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CMultiLineCommentExtractor::GetEndComment                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CMultiLineCommentExtractor::GetEndComment () const
{
    return m_strEndComment.c_str ();
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CMultiLineCommentExtractor::SetEndComment                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CMultiLineCommentExtractor::SetEndComment (const char* szMarker)
{
    if (NULL == szMarker)
        m_strEndComment.resize (0);
    else m_strEndComment = szMarker;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CMultiLineCommentExtractor::ExtractToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CMultiLineCommentExtractor::ExtractToken (const char* szData, 
                                                              std::string &strToken, 
                                                              eCommentState &eState)
{
    strToken.resize (0);
    int nBeginCommentLen = m_strBeginComment.length ();
    int nEndCommentLen = m_strEndComment.length ();

    if ((eNormal == eState) &&
        (strncmp (szData, m_strBeginComment.c_str (), nBeginCommentLen) != 0))
    {
        return szData;
    }
    
    //
    //Ищем конец комменария. если комментарий начался на текущей строке, то 
    //начинаем искать маркер конца сразу после маркера начала
    //

    int nOffset = 0;
    if (eNormal == eState)
        nOffset = nBeginCommentLen;

    char* pEndComment = strstr (szData + nOffset, m_strEndComment.c_str ());   
    
    if (pEndComment == NULL)        //вся строка закомментирована
    {
        eState = eMultilineComment;
        strToken = szData;
        return szData + strlen (szData);
    }

    strToken.assign (szData, pEndComment - szData + nEndCommentLen);
    eState = eNormal;

    return pEndComment + nEndCommentLen;
}

