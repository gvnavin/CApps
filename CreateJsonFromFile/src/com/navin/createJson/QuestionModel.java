package com.navin.createJson;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;

@AllArgsConstructor
@Data
@Builder
public class QuestionModel {
    
    private String questionNo;
    private String subject;
    private String chapter;
    private String section;
    private String question;
    private String option1;
    private String option2;
    private String option3;
    private String option4;
    private String answerKey;
    private String solution;
    
}
