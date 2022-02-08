///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           LineProcessor.cpp                                  
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


#include "LineProcessor.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CLineProcessor::CLineProcessor%                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CLineProcessor::CLineProcessor (IGramma *pGramma/* = NULL*/):
m_pGramma (pGramma),
m_eState (eNormal)
{

}

///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CLineProcessor::~CLineProcessor%
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CLineProcessor::~CLineProcessor ()
{

}

///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CLineProcessor::Process                                                         
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

int CLineProcessor::Process (const char *szData, 
                             std::string &strResult)
{
    strResult.resize (0);
    if (szData == NULL || m_pGramma == NULL) return 0;

    const char *szCurrentPos = szData;
    const char *szNewPos;
    std::string strToken;
    std::string strPlainText = "";

    m_pGramma->ClearTokenList ();
    
    while (*szCurrentPos != 0)
    {
        int nIdx;
        int nLexemmCount = m_pGramma->GetLexemmaCount ();

        for (nIdx = 0; nIdx < nLexemmCount; ++nIdx)
        {
            IGramma::SLexemma *pLexemma = m_pGramma->GetNthLexemma (nIdx);
            if (pLexemma == NULL)
                continue;

            szNewPos = pLexemma->m_pExtractor->ExtractToken (szCurrentPos, 
                                                             strToken,
                                                             m_eState);
            if (szNewPos == szCurrentPos)
            {
                //
                //Лексемма не найдена
                //
                continue;
            }

            if (strPlainText.length () > 0)
            {
                m_pGramma->PushToken (strPlainText, PLAIN_TEXT);
                strPlainText.resize (0);
            }

            m_pGramma->PushToken (strToken, pLexemma->m_nType);
            szCurrentPos = szNewPos;
            break;
        }
        
        if (nIdx >= nLexemmCount)
        {
            strPlainText += *szCurrentPos;
            ++szCurrentPos;
        }
        
    }
    //
    //Добавляем остаток строки
    //

    if (strPlainText.length () > 0)
    {
        m_pGramma->PushToken (strPlainText, PLAIN_TEXT);
    }

    m_pGramma->GenerateText (strResult);

    return 1;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CLineProcessor::GetState                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

eCommentState CLineProcessor::GetState () const
{
    return m_eState;
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CLineProcessor::SetState                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CLineProcessor::SetState (eCommentState eState)
{
    m_eState = eState;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CLineProcessor::GetGramma                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

IGramma* CLineProcessor::GetGramma () const
{
    return m_pGramma;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CLineProcessor::SetGramma                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void CLineProcessor::SetGramma (IGramma *pGramma)
{
    m_pGramma = pGramma;
}