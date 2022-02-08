///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           MultilineCommentExtractor.h                                  
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


#if !defined(AFX_MULTILINECOMMENTEXTRACTOR_H__5AC0485F_8E87_4C4B_959F_56B93197B434__INCLUDED_)
#define AFX_MULTILINECOMMENTEXTRACTOR_H__5AC0485F_8E87_4C4B_959F_56B93197B434__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SingleLineCommentExtractor.h"

class CMultiLineCommentExtractor : public CSingleLineCommentExtractor
{
public:
	CMultiLineCommentExtractor (const char *szBeginComment = NULL,
                                const char *szEndComment = NULL);
    virtual ~CMultiLineCommentExtractor ();

    const char* GetEndComment () const;
    void SetEndComment (const char* szMarker);

    virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState);
protected:
    std::string m_strEndComment;
};

#endif // !defined(AFX_MULTILINECOMMENTEXTRACTOR_H__5AC0485F_8E87_4C4B_959F_56B93197B434__INCLUDED_)
