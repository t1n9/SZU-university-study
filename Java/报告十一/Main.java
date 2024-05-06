package eleventh;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.concurrent.RecursiveAction;

class Review{
	String userID;
	String productID;
	String summary;
	Review(){
		userID = null;
		productID = null;
		summary = null;
	}
	void setUserId(String userID) {
		this.userID = userID;
	}
	void setProductID(String productID) {
		this.productID = productID;
	}
	void setSummary(String summary) {
		this.summary = summary;
	}
	String getUserID() {
		return userID;
	}
	String getProductID() {
		return productID;
	}
	String getSummary() {
		return summary;
	}
	
}

public class Main {
	static int sortNum[] = new int[100000];		// 最终顺序
	static int tmpSortNum[] = new int[100000];	
	static int max = 0;
	// 归并排序相关方法
	// 递归
	private static void mergeSort(String[] strs,String[] tmp,int left,int right) {
		if(left<right) {
			int center = (left+right)/2;
			mergeSort(strs,tmp,left,center);
			mergeSort(strs,tmp,center+1,right);
			merge(strs,tmp,left,center+1,right);
		}
	}
	// 合并
	static void merge(String[] strs,String[] tmp,int leftPos,int rightPos,int rightEnd) {
		int leftEnd = rightPos - 1;
		int tmpPos = leftPos;
		int numElements = rightEnd - leftPos + 1;
		
		while(leftPos<=leftEnd&&rightPos<=rightEnd){
            if(compare(strs[rightPos],strs[leftPos])==1) {
                tmp[tmpPos]=strs[leftPos];
            	tmpSortNum[tmpPos] = sortNum[leftPos];
            	tmpPos++;
            	leftPos++;
            }
            else {
                tmp[tmpPos]=strs[rightPos];
                tmpSortNum[tmpPos] = sortNum[rightPos];
            	tmpPos++;
            	rightPos++;
            }
        }
        while(leftPos<=leftEnd) {
            tmp[tmpPos]=strs[leftPos];
            tmpSortNum[tmpPos] = sortNum[leftPos];
            tmpPos++;
        	leftPos++;
        }
        
        while(rightPos<=rightEnd) {
            tmp[tmpPos]=strs[rightPos];
            tmpSortNum[tmpPos] = sortNum[rightPos];
            tmpPos++;
        	rightPos++;
        }
    
        for(int i = 0;i<numElements;i++,rightEnd--) {
        	strs[rightEnd] = tmp[rightEnd];
        	sortNum[rightEnd] = tmpSortNum[rightEnd];
        }
	}
	public static void mergeSort(String[] strs) {
		String[] tmp = new String[strs.length];
		mergeSort(strs,tmp,0,max-1);
	}
	
	// 字符串比较
	static int compare(String s1,String s2) {	// 返回1则前一个大
		int i = 0;
		while(s1.charAt(i) == s2.charAt(i)) {
			if(i==s1.length()-1&&i==s2.length()-1) {
				return 2;		// 两字符串相同
			}
			if(i>=s1.length()-1 || i>=s2.length()-1) {
				return 0;
			}
			i++; 
		}
		if(s1.charAt(i)>s2.charAt(i))
			return 1;
		return 0;
	}
	
	public static void main(String[] args) {
		try {
			FileReader fr = new FileReader("D:\\code\\JavaWorkSpace\\course\\eleventh\\Eleventh\\src\\Watches.txt");
			BufferedReader input = new BufferedReader(fr);
			FileWriter fw = new FileWriter("D:\\code\\JavaWorkSpace\\course\\eleventh\\Eleventh\\src\\review.txt");
			BufferedWriter output = new BufferedWriter(fw);
			
			Review []rev = new Review[100000];
			String s = null;
			String str_tmp = null;
			int i = 0;
			int j = 0;
			// 创建三元组对象
			while((s=input.readLine())!=null) {
				if(rev[i] == null)
					rev[i] = new Review();
				if(s.compareTo("") == 0) {
					i++;
				}else {
					str_tmp = s.substring(0, 11);
					if(str_tmp.compareTo("product/pro" ) == 0) {
						rev[i].setProductID(s.substring(19));
					}
					else if(str_tmp.compareTo("review/user") == 0) {
						rev[i].setUserId(s.substring(15));
					}
					else if(str_tmp.compareTo("review/summ") == 0) {
						rev[i].setSummary(s.substring(16));
					}
				}
			}
			
			// 排序
				// userID排序
			String []sortRev = new String[100000];
			int int_tmp = 0;
			for(i = 0;rev[i]!=null;i++) {
				sortNum[i] = i;
				tmpSortNum[i] = i;
				sortRev[i] = new String(rev[i].getUserID());
			}
			max = i;
			
			// 单线归并排序，速度还可以
			mergeSort(sortRev);
			
			// 单线冒泡排序，实在太慢
//			for(i = 0; i < max - 1; i++) {
//				for(j = 0; j < max - 1 - i;j++) {
//					if(compare(sortRev[j],sortRev[j+1]) == 1) {
//						str_tmp = sortRev[j];
//						int_tmp = sortNum[j];
//						sortRev[j] = sortRev[j+1];
//						sortNum[j] = sortNum[j+1];
//						sortRev[j+1] = str_tmp;
//						sortNum[j+1] = int_tmp;
//						System.out.println(sortNum[j]+" "+sortNum[j+1]);
//					}else {		// 测试
//						System.out.println(j+" "+sortRev[j]+" "+sortRev[j+1]);
////						System.out.println(j+" "+compare(sortRev[j],sortRev[j+1]));
//					}
//				}
//				System.out.println(i);
//			}
			
				// productID排序
			String []sortPro = new String[100000];
			for(i = 0;i<max;i++) {
				sortPro[i] = new String(rev[sortNum[i]].getProductID());
			}
			
			i = 0;j = 0;
			int m = 0;
			int n = 0;
			while(i<max && j<=max) {
				if(j != max-1)  {
					if(sortRev[i].compareTo(sortRev[j+1]) == 0) {
						j++;
						continue;
					}
					if(j-i == 0) {
						i++;
						j = i;
						continue;
					}
				}
				System.out.println(i+" "+j);
				// 从i位到j位冒泡排序(userID相同的数量较少)
				for(m = i; m < j; m++) {
					for(n = i; n - i < j - m;n++) {
						if(compare(sortPro[n],sortPro[n+1]) == 1) {
							str_tmp = sortPro[n];
							int_tmp = sortNum[n];
							sortPro[n] = sortPro[n+1];
							sortNum[n] = sortNum[n+1];
							sortPro[n+1] = str_tmp;
							sortNum[n+1] = int_tmp;
						}
					}
				}
				j++;
				i = j;
			}
			
			// 有排序测试
			i = 0;
			while(rev[i] !=null) {
				output.write(rev[sortNum[i]].getProductID()+";"+rev[sortNum[i]].getUserID()+";"+rev[sortNum[i]].getSummary()+"\n");
				i++;
			}
			// 无排序测试
//			i = 0;
//			while(rev[i] !=null) {
//				output.write(rev[i].getProductID()+";"+rev[i].getUserID()+";"+rev[i].getSummary()+"\n");
//				i++;
//			}
			
			output.flush();
			output.close();
			fw.close();
			input.close();
			fr.close();
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}
