package com.navin.createJson;

import java.io.File;
import java.io.IOException;
import java.util.List;

import org.apache.commons.io.FileUtils;

import com.google.gson.Gson;

public class Main {
	
	public static final String INPUT_FILE_NAME = "../c_questions.c";
	public static final String OUTPUT_FILE_NAME = "../SkillHelper/res/raw/json_10_2.txt";
	public static final int NO_OF_LINES_PER_QUESTION = 7;
	
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		jsonDecode();
	}
	
	public static void jsonDecode() throws IOException {
		List<String> lines = FileUtils.readLines(new File(INPUT_FILE_NAME));
		Question[] q = new Question[lines.size()/7];
		
		for(int i = 0 ; i < lines.size(); i += NO_OF_LINES_PER_QUESTION) {
			q[i/NO_OF_LINES_PER_QUESTION] = new Question(
					lines.get(i+0),
					lines.get(i+1),
					lines.get(i+2),
					lines.get(i+3),
					lines.get(i+4),
					lines.get(i+5),
					lines.get(i+6)
					);
			//System.out.println(q[i/7].getQuestion());
		}
		String str = new Gson().toJson(q);
		//str = str.replace("\\n", "\n");
		System.out.println(str);
		FileUtils.write(new File(OUTPUT_FILE_NAME), str);

	}
	
}
