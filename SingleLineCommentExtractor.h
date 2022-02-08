///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           SingleLineCommentExtractor.h                                  
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


#if !defined(AFX_SINGLELINECOMMENTEXTRACTOR_H__D91AC04D_A927_423B_AEE5_77A2705C767C__INCLUDED_)
#define AFX_SINGLELINECOMMENTEXTRACTOR_H__D91AC04D_A927_423B_AEE5_77A2705C767C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
                                        
#include "ITokenExtractor.h"

class CSingleLineCommentExtractor : public ITokenExtractor  
{
public:
	CSingleLineCommentExtractor (const char *szBeginComment = NULL);
	virtual ~CSingleLineCommentExtractor ();

    const char* GetBeginComment () const;
    void SetBeginComment (const char* szMarker);

    virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState);
protected:
    std::string m_strBeginComment;
};

#endif // !defined(AFX_SINGLELINECOMMENTEXTRACTOR_H__D91AC04D_A927_423B_AEE5_77A2705C767C__INCLUDED_)
