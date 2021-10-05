<template>
    <div id="booking" class="section" style="height:600px">
	<h3>{{$store.page_title}}</h3>
		<div class="section-center">
			<div class="container">
				<!--<div class="row">-->
					<div class="booking-form">
						<form>
							<div class="row">
								<div class="col-md-2">
									<div class="form-group">
										<span class="form-label">REG ID</span>
										<span class="form-label"><b>AUTO</b></span>
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Plant</span>
										<select class="form-control" v-model="Plant">
											<option v-for="plant in PlantTable" :value=plant> {{plant}}</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
								<div class="col-md-2">
									<div class="form-group">
										<span class="form-label">Position</span>
										<input class="form-control" type="text" placeholder="number" v-model="Pos">
									</div>
								</div>
								<div class="col-md-2">
									<div class="form-group">
										<span class="form-label">Type</span>
										<select class="form-control" v-model="Type">
											<option>Tracker</option>
											<option>Inverter</option>
											<option>Other (Please Comment!)</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
								<div class="col-md-2">
									<div class="form-group">
										<span class="form-label">Error Code</span>
										<input class="form-control" type="text" placeholder="text(optional)" v-model="ErrorCode">
									</div>
								</div>
							</div>
							<div class="row">
								<div class="col-md-9">
									<div class="form-group">
										<span class="form-label">Error Notes</span>
										<input class="form-control" type="text" placeholder="text" v-model="ErrorNotes" required="">
									</div>
								</div>
								<div class="col-md-3">
									<div class="form-group">
										<span class="form-label">AssignedMech</span>
										<select class="form-control" v-model="AssignedMech">
											<option v-for="mech in this.$store.MechNames" :value=mech> {{mech}}</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
							</div>
							<div class="row">
								<div class="col-md-3">
									<div class="form-btn">
										<button type="button" class="submit-btn" @click='NewError();'>save</button>
									</div>
								</div>
							</div>
						</form>
					</div>
				<!--</div>-->
			</div>
		</div>
	</div>
</template>
<script>
import $ from "jquery";
import {Time} from "@sexycoders/time.js"
export default {
    components: {
    },
    data() {
		return {
			Plant:"",
			Pos:"",
			Type:"",
			ErrorCode:"",
			ErrorNotes:"",
			AssignedMech:"",
			PlantTable:[]
		}
  },
    computed()
        {
        },
    mounted() {
		this.getPlantIdTable();
    },
    methods: 
		{
			getPlantIdTable()
				{
					console.log(this.$store.plants);
					Object.values(this.$store.plants).forEach((value) => {
						this.$data.PlantTable.push(value.ID);
					});
					console.log(this.$data.PlantTable);
				},
			NewError()
				{
					var senddata = Object.assign({},this.$data);
					if(senddata.Plant=="" || senddata.Pos=="" || senddata.ErrorNotes=="" || senddata.AssignedMech=="")
						alert("Please fill in all the required fields!!!");
					delete senddata.PlantTable;
					senddata.token=window.__auth__.oauth2.token;
					senddata=JSON.stringify(Object.values(senddata));
					console.log(senddata);
					$.ajax({
						type: 'POST',
						url: window.__SCD.datacenter+"/new_error",
						data:senddata, 
						success:
						(response) =>
							{
								var t=JSON.parse(response);
                                if(response=="NOAUTH")
                                    {
                                        this.$store.NOAUTH=1;
                                        return;
                                    }
								else
									{
										alert("Error "+t.reg_id+" succcesfully registered.");
										this.$router.push("errors");
									}
							},
							async:false
							});
				},
			setTitle(title)
				{
					this.$store.page_title=title;
				},
        },
     created()
        {
			this.setTitle("new Error");
        }
};
</script>
<style>
.section {
	position: relative;
	height: 100vh;
}

.section .section-center {
	position: absolute;
	top: 50%;
	left: 0;
	right: 0;
	-webkit-transform: translateY(-50%);
	transform: translateY(-50%);
}

#booking {
	font-family: 'PT Sans', sans-serif;
	/*background-image: url('../img/background.jpg');*/
	background-size: cover;
	background-position: center;
}

.booking-form {
	background: rgba(0, 0, 0, 0.7);
	padding: 40px;
	border-radius: 6px;
}

.booking-form .form-group {
	position: relative;
	margin-bottom: 20px;
}

.booking-form .form-control {
	background-color: #fff;
	height: 50px;
	color: #191a1e;
	border: none;
	font-size: 16px;
	font-weight: 400;
	-webkit-box-shadow: none;
	box-shadow: none;
	border-radius: 40px;
	padding: 0px 25px;
}

.booking-form .form-control::-webkit-input-placeholder {
	color: rgba(82, 82, 84, 0.4);
}

.booking-form .form-control:-ms-input-placeholder {
	color: rgba(82, 82, 84, 0.4);
}

.booking-form .form-control::placeholder {
	color: rgba(82, 82, 84, 0.4);
}

.booking-form input[type="date"].form-control:invalid {
	color: rgba(82, 82, 84, 0.4);
}

.booking-form select.form-control {
	-webkit-appearance: none;
	-moz-appearance: none;
	appearance: none;
}

.booking-form select.form-control+.select-arrow {
	position: absolute;
	right: 10px;
	bottom: 6px;
	width: 32px;
	line-height: 32px;
	height: 32px;
	text-align: center;
	pointer-events: none;
	color: rgba(0, 0, 0, 0.3);
	font-size: 14px;
}

.booking-form select.form-control+.select-arrow:after {
	content: '\279C';
	display: block;
	-webkit-transform: rotate(90deg);
	transform: rotate(90deg);
}

.booking-form .form-label {
	display: block;
	margin-left: 20px;
	margin-bottom: 5px;
	font-weight: 400;
	text-transform: uppercase;
	line-height: 24px;
	height: 24px;
	font-size: 12px;
	color: #fff;
}

.booking-form .form-checkbox input {
	position: absolute !important;
	margin-left: -9999px !important;
	visibility: hidden !important;
}

.booking-form .form-checkbox label {
	position: relative;
	padding-top: 4px;
	padding-left: 30px;
	font-weight: 400;
	color: #fff;
}

.booking-form .form-checkbox label+label {
	margin-left: 15px;
}

.booking-form .form-checkbox input+span {
	position: absolute;
	left: 2px;
	top: 4px;
	width: 20px;
	height: 20px;
	background: #fff;
	border-radius: 50%;
}

.booking-form .form-checkbox input+span:after {
	content: '';
	position: absolute;
	top: 50%;
	left: 50%;
	width: 0px;
	height: 0px;
	border-radius: 50%;
	background-color: #f23e3e;
	-webkit-transition: 0.2s all;
	transition: 0.2s all;
	-webkit-transform: translate(-50%, -50%);
	transform: translate(-50%, -50%);
}

.booking-form .form-checkbox input:not(:checked)+span:after {
	opacity: 0;
}

.booking-form .form-checkbox input:checked+span:after {
	opacity: 1;
	width: 10px;
	height: 10px;
}

.booking-form .form-btn {
	margin-top: 27px;
}

.booking-form .submit-btn {
	color: #fff;
	background-color: #f23e3e;
	font-weight: 400;
	height: 50px;
	font-size: 14px;
	border: none;
	width: 100%;
	border-radius: 40px;
	text-transform: uppercase;
	-webkit-transition: 0.2s all;
	transition: 0.2s all;
}

.booking-form .submit-btn:hover,
.booking-form .submit-btn:focus {
	opacity: 0.9;
}
</style>

