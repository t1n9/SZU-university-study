package eleventh;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class User{
	String userID;
	String productID;
	User(){
		userID = null;
		productID = null;
	}
	User(String userID,String productID){
		this.userID = userID;
		this.productID = productID;
	}
	void setUserId(String userID) {
		this.userID = userID;
	}
	void setProductID(String productID) {
		this.productID = productID;
	}
	String getUserID() {
		return userID;
	}
	String getProductID() {
		return productID;
	}
}

public class Main2 {
	static int max;
	static int sortNum[] = new int[100000];
	static int tmpSortNum[] = new int[100000];	
	// 归并排序
 
    //递归
    static void mergeSort(float[] nums,float[] tmp,int left,int right){
        if(left<right){
            int center = (left+right)/2;
            mergeSort(nums,tmp,left,center);
            mergeSort(nums,tmp,center+1,right);
            merge(nums,tmp,left,center+1,right);
        }
    }
 
    //合并
    static void merge(float[] nums,float[] tmp,int leftPos, int rightPos, int rightEnd){
        int leftEnd = rightPos-1;
        int tmpPos = leftPos;
        int numElements = rightEnd - leftPos + 1;
    
        while(leftPos<=leftEnd&&rightPos<=rightEnd){
            if(nums[rightPos]>nums[leftPos]) {
                tmp[tmpPos]=nums[leftPos];
            	tmpSortNum[tmpPos] = sortNum[leftPos];
            	tmpPos++;
            	leftPos++;
            }
            else {
                tmp[tmpPos]=nums[rightPos];
                tmpSortNum[tmpPos] = sortNum[rightPos];
            	tmpPos++;
            	rightPos++;
            }
        }
        while(leftPos<=leftEnd) {
            tmp[tmpPos]=nums[leftPos];
            tmpSortNum[tmpPos] = sortNum[leftPos];
            tmpPos++;
        	leftPos++;
        }
        
        while(rightPos<=rightEnd) {
            tmp[tmpPos]=nums[rightPos];
            tmpSortNum[tmpPos] = sortNum[rightPos];
            tmpPos++;
        	rightPos++;
        }
    
        for(int i = 0;i<numElements;i++,rightEnd--) {
        	nums[rightEnd] = tmp[rightEnd];
        	sortNum[rightEnd] = tmpSortNum[rightEnd];
        }
    }
    static void mergeSort(float[] nums){
        float[] tmp = new float[nums.length];
        mergeSort(nums,tmp,0,max-1);
    }
    
	
	
	// 计算相似度
	static float getSimilarityRatio(String str, String target) {
		int d[][]; // 矩阵
		int n = str.length();
		int m = target.length();
		int i; // 遍历str的
		int j; // 遍历target的
		char ch1; // str的
		char ch2; // target的
		int temp; // 记录相同字符,在某个矩阵位置值的增量,不是0就是1
		if (n == 0 || m == 0) {
			return 0;
		}
		d = new int[n + 1][m + 1];
		for (i = 0; i <= n; i++) { // 初始化第一列
			d[i][0] = i;
		}

		for (j = 0; j <= m; j++) { // 初始化第一行
			d[0][j] = j;
		}

		for (i = 1; i <= n; i++) { // 遍历str
			ch1 = str.charAt(i - 1);
			// 去匹配target
			for (j = 1; j <= m; j++) {
				ch2 = target.charAt(j - 1);
				if (ch1 == ch2 || ch1 == ch2 + 32 || ch1 + 32 == ch2) {
					temp = 0;
				} else {
					temp = 1;
				}
				// 左边+1,上边+1, 左上角+temp取最小
				d[i][j] = Math.min(Math.min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + temp);
			}
		}
		return (1 - (float) d[n][m] / Math.max(str.length(), target.length())) * 100F;
	}
	
	
	public static void main(String[] args) {
		try {
			FileReader fr = new FileReader("D:\\code\\JavaWorkSpace\\course\\eleventh\\Eleventh\\src\\review.txt");
			BufferedReader input = new BufferedReader(fr);
			FileWriter fw = new FileWriter("D:\\code\\JavaWorkSpace\\course\\eleventh\\Eleventh\\src\\userNeighborhood.txt");
			BufferedWriter output = new BufferedWriter(fw);

			int i = 0;
			int j = 1;
			String s = null;
			User []u = new User[100000];
			String []tmp = new String[3];
			while((s=input.readLine())!=null) {
				tmp = s.split(";");
				u[i] = new User();
				u[i].setProductID(tmp[0]);
				u[i].setUserId(tmp[1]);
				i++;
			}
			u[i] = new User("","");

			String []userID = new String[100000];
			String [] beCompared = new String[100000];
			
			
			i=0;
			j=0;
			int flag = 0;
			while(u[i+1]!=null) {
				if(flag == 0) {
					beCompared[j] = new String("");
					beCompared[j]+=u[i].getUserID()+";";
					beCompared[j]+=u[i].getProductID();
				}
				if(u[i].getUserID().compareTo(u[i+1].getUserID()) == 0) {
					flag = 1;
					beCompared[j]+=u[i+1].getProductID();
				}else {
					flag = 0;
					j++;
				}
				i++;
			}
			max = j;
			
			// 测试
//			for(i = 0;beCompared[i]!=null;i++) {
//				System.out.println(beCompared[i]);
//			}
			
			
			float [][]similarity = new float[100000][10];
			float []s_tmp = new float[100000];
			for(i = 0;beCompared[i]!=null;i++) {
				output.write(beCompared[i].split(";")[0]+";");
				for(int k = 0;beCompared[k]!=null;k++)
					sortNum[k] = k;
				for(j = 0;beCompared[j]!=null;j++) {
					if(i == j)
						continue;
					s_tmp[j] = getSimilarityRatio(beCompared[i],beCompared[j]);
				}
				mergeSort(s_tmp);
				for(int k = 0;k<10;k++) {
					output.write(beCompared[sortNum[max-1-k]].split(";")[0]+";");
				}
				output.newLine();
			}
			
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
