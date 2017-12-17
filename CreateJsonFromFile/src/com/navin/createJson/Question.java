package com.navin.createJson;
/**
 * 
 */

/**
 * @author gnavin
 *
 */
public class Question {

	private String question;
	private String[] answers = new String[4];
	private boolean[] answers_flag;
	private int correct_answer;
	private String explanation;

	public Question(
			String ques,
			String ans0,
			String ans1,
			String ans2,
			String ans3,
			String correct_an,
			String explan) {
		
		question = ques;
		answers[0] = ans0;
		answers[1] = ans1;
		answers[2] = ans2;
		answers[3] = ans3;
		try {
		correct_answer = Integer.parseInt(correct_an);
		} catch (Exception e) {
			System.out.println(ques);
			System.out.println(ans0);
			System.out.println(ans1);
			System.out.println(ans2);
			System.out.println(ans3);
			throw e;
		}
		if ( correct_answer < 0 && correct_answer > 4)
			 throw new IllegalArgumentException(ques);
		explanation = explan;
		
		System.out.println(ques);
		System.out.println(ans0);
		System.out.println(ans1);
		System.out.println(ans2);
		System.out.println(ans3);
		System.out.println(explan);
		System.out.println("--------------------------------------------------------");
		
	}

	public Question() {
	}
	
	public String getQuestion() {
		return question;
	}
	
	public String getOption(int i) {
		return answers[i];
	}
	
	public String getOption_0() {
		return answers[0];
	}
		
	public String getOption_1() {
		return answers[1];
	}
	
	public String getOption_2() {
		return answers[2];
	}
	
	public String getOption_3() {
		return answers[3];
	}
	
	public int getCorrectAnswerIndex() {
		return correct_answer;
	}
	
	public String getCorrectAnswerText() {
		return answers[correct_answer];
	}
	
	public String getExplanation() {
		return explanation;
	}
	
}
