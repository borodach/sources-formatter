///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           ITokenExtractor.h                                  
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


#if !defined(AFX_ITOKENEXTRACTOR_H__03A99C35_97A1_4030_9E8F_EB10ECE601CE__INCLUDED_)
#define AFX_ITOKENEXTRACTOR_H__03A99C35_97A1_4030_9E8F_EB10ECE601CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

enum eCommentState
{
    eNormal,
    eMultilineComment
};

class ITokenExtractor  
{
public:
    virtual const char* ExtractToken (const char* szData, 
                                      std::string &strToken, 
                                      eCommentState &eState) = 0;
	virtual ~ITokenExtractor();
};

#endif // !defined(AFX_ITOKENEXTRACTOR_H__03A99C35_97A1_4030_9E8F_EB10ECE601CE__INCLUDED_)
