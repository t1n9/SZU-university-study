package sixth;

import java.util.*;

public class Web_word {
	//查找单词是否已存在数组中
	static boolean isExist(String[] words,int len, String word) {
		for(int i = 0; i<len;i++) {
			if(word.equals(words[i])) {
				return true;
			}
		}
		return false;
	}
	//查找单词在数组中的下标
	static int place(String[] words,int len,String word) {
		for(int i = 0;i<len;i++) {
			if(word.equals(words[i])) {
				return i;
			}
		}
		return 0;
	}
	
	public static void main(String[] args) {
		int len = 0;
		String []words = new String[1000];
		int []time = new int[1000];
		int []top50 = new int[50];
		int i,j,mp = 0,max;
		//文章以字符串方式引入
		String article = "About"
				+ " Shenzhen University (SZU) is committed to excellence in teaching, research and social service. Sticking to the motto of “self-reliance, self-discipline, self-improvement”, the University is dedicated to serving the Shenzhen Special Economic Zone (SEZ), demonstrating China’s reform and opening up and pioneering change in higher education."
				+ " SZU, which is based in Shenzhen, China’s first Special Economic Zone and a key city in the Guangdong-Hong Kong-Macau Greater Bay Area, is distinctively known as an Experimental University in higher education with its reforms in the sector acknowledged in Mainland China."
				+ " Established in 1983, SZU received support from top Chinese universities including Peking University, Tsinghua University and Renmin University of China in the founding of new schools. In the past decades, the University has undergone rapid growth and has become a comprehensive university with complete disciplines, top-ranked academic and research institutes and awe-inspiring faculty. SZU faculty members are engaged with teaching and research for the betterment of society. They are devoted to seeking solutions to pressing global challenges and promoting innovation."
				+ " SZU offers a wide array of undergraduate and graduate programs and provides students with an interdisciplinary and inclusive multicultural learning environment. Students in SZU enjoy the plenty resources and facilities of both the SEZ and the University, pursue academic excellence and discover new interests and opportunities in a fast-changing era."
				+ " SZU is an integral part of the SEZ, a thriving technology and innovation hub. With four campuses in Yuehai, Canghai, Lihu and Luohu, the University vigorously conducts leading researches in various fields and collaborates with high-tech enterprises in the community for technology transfer. SZU strives to provide a high-quality and effective education and develop in each SZU member the ability and passion to innovate and contribute to social progress and development, and encourages talented young people to start entrepreneurship in SZU. Our alumni including Tencent have founded dozens of innovative companies with significant influence."
				+ " SZU is accelerating its pace toward internationalization, providing a variety of global learning opportunities. The University has established partnerships with numbers of overseas universities to offer exceptional exchange programs, joint degree programs, research collaborations, and a variety of other forms of collaborations with international partners. Students from all over the world are welcomed in SZU. In the city noted for its urban vitality and natural beauty, students can explore the most attractive parts of China, pursue their passion and develop their interests, perspectives and abilities.";
		//去掉标点
		article = article.replaceAll("[\\pP‘’“”]", "");
		//不区分大小写，故所有字符都转化为小写
		article = article.toLowerCase();
		Scanner scanner = new Scanner(article);
		scanner.useDelimiter("[^a-zA-Z.]+");
		while(scanner.hasNext()) {
			try {
				String word = scanner.next();
				//单词不存在则在字符串数组中创建一个新的单词串
				if(!isExist(words,len,word)) {
					words[len] = word;
					time[len]++;
					len++;
				}else {		//单词存在则找出其下标
					time[place(words,len,word)]++;
				}
			}
			catch(InputMismatchException exp) {
				String t = scanner.next();
			}
		}
		int []time_cp = new int[1000];
		for(i = 0;i<1000;i++)
			time_cp[i] = time[i];
		
		//记录出现次数最多的单词的下标
		for(i = 0;i<50;i++) {
			max = 0;
			for(j = 0;j<len;j++) {
				if(time_cp[j]>max) {
					max = time_cp[j];
					//出现最多次的单词的下标，记为mp
					mp = j;
				}
			}
			time_cp[mp] = 0;
			top50[i] = mp;
		}
		
		for(i = 0;i<50;i++) {
			int t = top50[i];
			System.out.println("["+(i+1)+"]"+words[t]+":"+time[t]);
		}
	}

}
