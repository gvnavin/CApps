package com.navin.createJson;

import com.google.api.client.http.GenericUrl;
import com.google.api.client.http.HttpContent;
import com.google.api.client.http.HttpRequest;
import com.google.api.client.http.HttpRequestFactory;
import com.google.api.client.http.HttpRequestInitializer;
import com.google.api.client.http.HttpResponse;
import com.google.api.client.http.HttpTransport;
import com.google.api.client.http.javanet.NetHttpTransport;
import com.google.api.client.http.json.JsonHttpContent;
import com.google.api.client.json.JsonFactory;
import com.google.api.client.json.JsonObjectParser;
import com.google.api.client.json.jackson2.JacksonFactory;
import com.google.gson.Gson;
import com.opencsv.CSVReader;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MainCSV2Json {
    
    public static final String CSV_INPUT_FILE_NAME = "content_updated.csv";
    public static final String OUTPUT_FILE_NAME = "json_content.txt";
    
    /**
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        
        try (final FileReader fileReader = new FileReader(CSV_INPUT_FILE_NAME)) {
            final CSVReader csvReader = new CSVReader(fileReader);
            String[] line;
            List<QuestionModel> questionModels = new ArrayList<>();
            while ((line = csvReader.readNext()) != null) {
                final QuestionModel questionModel = QuestionModel
                    .builder()
                    .questionNo(line[0])
                    .subject(line[1])
                    .chapter(line[2])
                    .section(line[3])
                    .question(line[4])
                    .option1(line[5])
                    .option2(line[6])
                    .option3(line[7])
                    .option4(line[8])
                    .answerKey(line[9])
                    .solution(line[10])
                    .build();
                
                questionModels.add(questionModel);
                //System.out.println("content.toString() = " + questionModel.toString())
                
                
                final String individualQuestion = new Gson().toJson(questionModel);
                run(questionModel, individualQuestion);
                System.out.println(individualQuestion);
                System.out.println();
                
            }
            
            
            String jsonStr = new Gson().toJson(questionModels);
            //System.out.println("jsonStr = " + jsonStr);
            
            FileUtils.write(new File(OUTPUT_FILE_NAME), jsonStr);
        }
    }
    
    static final HttpTransport HTTP_TRANSPORT = new NetHttpTransport();
    static final JsonFactory JSON_FACTORY = new JacksonFactory();
    
    private static void run(final QuestionModel questionModel, final String individualQuestion) throws IOException {
        HttpRequestFactory requestFactory =
            HTTP_TRANSPORT.createRequestFactory(new HttpRequestInitializer() {
                @Override
                public void initialize(HttpRequest request) {
                    request.setParser(new JsonObjectParser(JSON_FACTORY));
                }
            });
    
        final Map<String, String> json = new HashMap<String, String>();
        
        json.put("questionNo", questionModel.getQuestionNo());
        json.put("subject", questionModel.getSubject());
        json.put("section", questionModel.getSection());
        json.put("question", questionModel.getQuestion());
        json.put("option1", questionModel.getOption1());
        json.put("option2", questionModel.getOption2());
        json.put("option3", questionModel.getOption3());
        json.put("option4", questionModel.getOption4());
        json.put("answerKey", questionModel.getAnswerKey());
        json.put("solution", questionModel.getSolution());
        
        final HttpContent content = new JsonHttpContent(new JacksonFactory(), json);
        final HttpRequest request = requestFactory.buildPostRequest(
            new GenericUrl("http://localhost:9200/questions/" + questionModel.getQuestionNo()),
            content
        );
        
        final HttpResponse response = request.execute();
        System.out.println("response = " + response.getContent().toString());
    }
}
