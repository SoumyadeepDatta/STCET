public class ClassNnetwork
{
	static String class_id(String str)
		{
			int index = str.indexOf('.');
			String sub = str.substring(0,index);
			int ip = Integer.parseInt(sub);
			if(ip>=1 && ip<=127)
				return "A";
			else if(ip>=128 && ip<=191)
				return "B";
			else if(ip>=192 && ip<=223)
				return "C";
			else if(ip>=224 && ip<=239)
				return "D";
			else
				return "E";
		}

	static void net_host(String str,String ip)
	{
		String network = "";
		if(ip =="A")
		{
			int index = str.indexOf('.');
			String sub = str.substring(0,index);
			network = sub+".0.0.0";
		}
		else if(ip =="B")
		{
			int index = -1;
			int dot = 2;
			for(int i=0;i<str.length();i++){
				if(str.charAt(i)=='.')
				{
					dot = dot-1;
					if(dot == 0){
						index = i;
						break;
					}
				}
			}
			String sub = str.substring(0,index);
			network = sub+"0.0";
		}
		else if(ip =="C")
		{
			int index = -1;
			int dot = 3;
			for(int i=0;i<str.length();i++){
				if(str.charAt(i)=='.')
				{
					dot = dot-1;
					if(dot == 0){
						index = i;
						break;
					}
				}
			}
			String sub = str.substring(0,index);
			network = sub+".0";
		}
		else if(ip =="D"||ip=="E")
			System.out.println("No network ID");
		
		System.out.println("Network ID : "+network);
	}
	public static void main(String args[])
	{
		String str = "196.168.0.1";
		String ip = class_id(str);
		System.out.println("IP Adress belongs to Class "+ip);
		net_host(str,ip);
	}
}