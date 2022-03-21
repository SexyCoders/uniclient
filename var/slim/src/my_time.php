<?php
class Time{
	public $second;
	public $minute;
	public $hour;
	public $weekday;
	public $day;
	public $month;
	public $year;

	private $_week_days=array("Monday",
					"Tuesday",
					"Thursday",
					"Wednessday",
					"Thursday",
					"Friday",
					"Saturday",
					"Sunday");

	private $_months=array("January",
					"February",
					"March",
					"April",
					"May",
					"June",
					"July",
					"August",
					"September",
					"October",
					"November",
					"December");
		function get_second()
			{
			return $this->second;
			}
		function get_minute()
			{
			return $this->minute;
			}
		function get_hour()
			{
			return $this->hour;
			}
		function get_weekday()
			{
			return $this->weekday;
			}
		function get_day()
			{
			return $this->day;
			}
		function get_month()
			{
			return $this->month;
			}
		function get_year()
			{
			return $this->year;
			}
		function getTime()
			{
				$this->weekday=date("w");
				$this->second=date("s");
				$this->minute=date("i");
				$this->hour=date("H");
				$this->day=date("d");
				$this->month=date("m");
				$this->year=date("y");
			}
		function fromString($str)
			{
				$T=split(";",$str);
				$this->weekday=$T[0];
				$this->day=$T[1];
				$this->month=$T[2];
				$this->year=$T[3];
				$this->hour=$T[4];
				$this->minute=$T[5];
				$this->second=$T[6];
			}
		function toString()
			{
				$DATE="";
				$DATE.=$this->weekday.";";
				$DATE.=$this->day.";";
				$DATE.=$this->month.";";
				$DATE.=$this->year.";";
				$DATE.=$this->hour.";";
				$DATE.=$this->minute.";";
				$DATE.=$this->second.";";
			return $DATE;
			}
		function toStringf($format,$time_format,$week_day_flag)
			{
				$DATE="";
				if($week_day_flag)
					$DATE.=$this->_week_days[$this->weekday]." ";
				$argc=strlen($format);
				if($argc<2)
					return "At least 2 parameters required!";
				$delim="";
				$short_flag=0;
				for($j=0;$j<$argc-1;$j++)
					{
						if($format[$j]=='s')
							{
								$short_flag=1;
								$delim=$argc==5?$format[4]:'-';
								break;
							}
						else
							$delim=' ';
					}
				//console.log(delim);
				for($j=0;$j<($argc-2);$j++)
					{
						//console.log(j);
						//console.log(argc-2);
						//console.log(DATE);
						switch($format[$j])
							{
								case 'y':
									$DATE.=$short_flag?substr($this->year,-2):$this->year;
									$j!=2?$DATE.=$delim:"";
									break;
								case 'm':
									if($short_flag)
											$DATE.=$this->month;
									else
											$DATE.=$this->_months[$this->month-1];
									$j!=2?$DATE.=$delim:"";
									break;
								case 'd':
									$DATE.=$this->day;
									$j!=2?$DATE.=$delim:"";
									break;
							}
					}
				if($time_format=='m')
					$DATE.=" ".$this->hour.$this->minute;
				else
					$DATE.=" ".$this->hour.":".$this->minute;
			return $DATE;
			}
		function _to_min()
			{
			return ((($this->month-1)*43800)+(($this->day-1)*1440)+($this->hour*60)+($this->minute));
			}

		function min()
			{
			return $this->_to_min();
			}

		function check_before_minutes($min)
			{
				$tmp=new Time();
				$tmp->getTime();
				$tmp_min=$tmp->min();
				$this_min=$this->min();
				if($this_min+$min>=$tmp_min)
					return 1;
				else
					return 0;
			}
		function check_after_minutes($min)
			{
				$tmp=new Time();
				$tmp->getTime();
				$tmp_min=$tmp->min();
				$this_min=$this->min();
				if($this_min+$min<$tmp_min)
					return 0;
				else
					return 1;
			}
		function compare($comp)
			{
				if(gettype($comp)=="object")
					{
						$neq=0;
						if($this->weekday!=$comp->weekday)
							$neq=1;
						else if($this->day!=$comp->day)
							$neq=1;
						else if($this->month!=$comp->month)
							$neq=1;
						else if($this->year!=$comp->year)
							$neq=1;
						else if($this->hour!=$comp->hour)
							$neq=1;
						else if($this->minute!=$comp->minute)
							$neq=1;
						else if($this->second!=$comp->second)
							$neq=1;
						if($neq==1)
							{
								if($this->min()>$comp->min())
									return 1;
								else
									return -1;
							}
						else
							return 0;

					}
				else
					{
						if($this->min()==$comp)
							return 0;
						else if($this->min()>$comp)
							return 1;
						else
							return -1;
					}
			return 1;
			}
};

//$test=new Time();
//$test->getTime();
//echo $test->toString();
//echo $test->toStringf("dmyl-","c",1);
?>
