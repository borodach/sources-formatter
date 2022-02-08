///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           LineProcessor.h                                  
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


#if !defined(AFX_LINEPROCESSOR_H__CD5F1536_DB8C_436B_AED2_AD60CB5A16F8__INCLUDED_)
#define AFX_LINEPROCESSOR_H__CD5F1536_DB8C_436B_AED2_AD60CB5A16F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "ITokenExtractor.h"
#include "IGramma.h"

class CLineProcessor  
{
public:
    CLineProcessor (IGramma *pGramma = NULL);
    virtual ~CLineProcessor ();

    void SetGramma (IGramma *pGramma);
	IGramma* GetGramma () const;
    void SetState (eCommentState eState);
	eCommentState GetState () const;
	
    virtual int Process (const char *szData, 
                         std::string &strResult);

protected:
    IGramma *m_pGramma;
    eCommentState m_eState;
};

#endif // !defined(AFX_LINEPROCESSOR_H__CD5F1536_DB8C_436B_AED2_AD60CB5A16F8__INCLUDED_)
