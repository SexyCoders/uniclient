<template>
    <div id="booking" class="section" style="height:90vh">
	<h3>{{$store.page_title}}</h3>
		<div class="section-center">
			<div class="container">
				<!--<div class="row">-->
					<div class="booking-form">
						<form>
							<div class="row">
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">ID</span>
										<input class="form-control" type="text" placeholder="plant id (text)" v-model="ID" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Power</span>
										<input class="form-control" type="text" placeholder="power in kW" v-model="Power" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Owner</span>
										<select class="form-control" v-model="Owner">
											<option v-for="customer in this.$store.data.customers" :value=customer> {{customer.Company}}</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">County</span>
										<select class="form-control" v-model="County">
											<option v-for="county in this.$data.Counties" :value=county> {{county}}</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Borough</span>
										<input class="form-control" type="text" placeholder="borough (text)" v-model="Borough" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Location</span>
										<input class="form-control" type="text" placeholder="location (text)" v-model="Location" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Area</span>
										<input class="form-control" type="number" placeholder="area (number)" v-model="Area" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">No of Panels</span>
										<input class="form-control" type="number" placeholder="Number of panels (number)" v-model="NPanels" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Panel</span>
										<select class="form-control" v-model="Panel">
											<option v-for="panel in this.$data.Panels" :value=panel> {{panel}}</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Strings</span>
										<input class="form-control" type="text" placeholder="strings (text)" v-model="Strings" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Mounter</span>
										<select class="form-control" v-model="Mounter">
											<option v-for="mounter in this.$data.Mounters" :value=mounter> {{mounter}}</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Inverter</span>
										<select class="form-control" v-model="Mounter">
											<option v-for="inverter in this.$data.Inverters" :value=inverter> {{inverter}}</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Circuit Board</span>
										<select class="form-control" v-model="CBoard">
											<option v-for="cboard in this.$data.Cboards" :value=cboard> {{cboard}}</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Constructor</span>
										<select class="form-control" v-model="Constructor">
											<option v-for="constructor in this.$data.Constructors" :value=constructor> {{constructor}}</option>
										</select>
										<span class="select-arrow"></span>
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Connection Number</span>
										<input class="form-control" type="number" placeholder="Connectino Numbmer (number)" v-model="ConnNumber" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Connection Date</span>
										<input class="form-control" type="date" placeholder="Connectino Date (date)" v-model="ConnDate" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Tracker Begin Date</span>
										<input class="form-control" type="date" placeholder="Tracker Begin Date (date)" v-model="TrackBegin" required="">
									</div>
								</div>
								<div class="col-md-4">
									<div class="form-group">
										<span class="form-label">Selling Price</span>
										<input class="form-control" type="number" placeholder="Selling Price (number)" v-model="Price" required="">
									</div>
								</div>
								<!--<div class="col-md-2">-->
									<!--<div class="form-group">-->
										<!--<span class="form-label">Error Code</span>-->
										<!--<input class="form-control" type="text" placeholder="text(optional)" v-model="ErrorCode">-->
									<!--</div>-->
								<!--</div>-->
							<!--</div>-->
							<!--<div class="row">-->
								<!--<div class="col-md-9">-->
									<!--<div class="form-group">-->
										<!--<span class="form-label">Error Notes</span>-->
										<!--<input class="form-control" type="text" placeholder="text" v-model="ErrorNotes" required="">-->
									<!--</div>-->
								<!--</div>-->
								<!--<div class="col-md-3">-->
									<!--<div class="form-group">-->
										<!--<span class="form-label">AssignedMech</span>-->
										<!--<select class="form-control" v-model="AssignedMech">-->
											<!--<option v-for="mech in this.$store.MechNames" :value=mech> {{mech}}</option>-->
										<!--</select>-->
										<!--<span class="select-arrow"></span>-->
									<!--</div>-->
								<!--</div>-->
							</div>
							<div class="row">
								<div class="col-md-3">
									<div class="form-btn">
										<button type="button" class="submit-btn" @click='NewPlant();'>save</button>
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
			Counties:"",
			Panels:"",
			Mounters:"",
			Inverters:"",
			Cboards:"",
			Constructors:"",
			toReturn:{}
		}
  },
    computed()
        {
        },
    mounted() {
		this.getConstructorCompanies();
		this.getCountyNames();
		this.getInverterModels();
		this.getCboardModels();
		this.getPanelModels();
		this.getMounterNames();
		this.getCustomerData();
    },
    methods: 
		{
			compare_customers(a, b) {
				// Use toUpperCase() to ignore character casing
				const CompA = a.Company.toUpperCase();
				const CompB = b.Company.toUpperCase();

				let comparison = 0;
				if (CompA > CompB) {
					comparison = 1;
				} else if (CompA < CompB) {
					comparison = -1;
				}
				return comparison;
				},

			setTitle(title)
				{
					this.$store.page_title=title;
				},
			storeCounties(t)
				{
					this.$data.Counties=t;
				},
			storeMounters(t)
				{
					this.$data.Mounters=t;
				},
			storePanels(t)
				{
					this.$data.Panels=t;
				},
			storeCboards(t)
				{
					this.$data.Cboards=t;
				},
			storeInverters(t)
				{
					this.$data.Inverters=t;
				},
			storeConstructors(t)
				{
					this.$data.Constructors=t;
				},
			getCustomerData(){
				$.ajax({
					type: 'POST',
					url: this.$store.datacenter+"/get_customer_data_full",
					data: JSON.stringify([this.$store.oauth_token]),
					success:
					(response) =>
						{
							var t=JSON.parse(atob(response));
							if(response=="NOAUTH")
								{
									this.$store.force_auth=true;
									this.$store.oauth_token=null;
									return;
								}
							//this.storeCustomers(Object.values(JSON.parse(response)).filter((customer)=>customer.ID!=1).sort(this.compare_customers));
							this.$store.data.customers=t.filter((customer)=>customer.ID!=1).sort(this.compare_customers);
							//console.log(this.$store.Customers);
							//this.onGridReady();
						},
					async:false
					});
				},
			getCountyNames(){
				$.ajax({
					type: 'POST',
					url: this.$store.datacenter+"/get_county_names",
					data: JSON.stringify([this.$store.oauth_token]),
					success:
					(response) =>
						{
							var t=JSON.parse(atob(response));
							if(response=="NOAUTH")
								{
									this.$store.state.force_auth=true;
									return;
								}
							this.storeCounties(t.filter((county)=>county!='dummy').sort());
							//console.log(this.$data.Counties);
						},
						async:false
						});
			},
			getMounterNames(){
				$.ajax({
					type: 'POST',
					url: this.$store.datacenter+"/get_mounter_names",
					data: JSON.stringify([this.$store.oauth_token]),
					success:
					(response) =>
						{
							var t=JSON.parse(atob(response));
							if(response=="NOAUTH")
								{
									this.$store.state.force_auth=true;
									return;
								}
							this.storeMounters(t.filter((mounter)=>mounter!='dummy').sort());
							//console.log(this.$data.Mounters);
						},
						async:false
						});
			},
			getPanelModels(){
				$.ajax({
					type: 'POST',
					url: this.$store.datacenter+"/get_panel_models",
					data: JSON.stringify([this.$store.oauth_token]),
					success:
					(response) =>
						{
							var t=JSON.parse(atob(response));
							if(response=="NOAUTH")
								{
									this.$store.state.force_auth=true;
									return;
								}
							this.storePanels(t.filter((panel)=>panel!='DUMMY').sort());
							//console.log(this.$data.Panels);
						},
						async:false
						});
			},
			getCboardModels(){
				$.ajax({
					type: 'POST',
					url: this.$store.datacenter+"/get_cboard_models",
					data: JSON.stringify([this.$store.oauth_token]),
					success:
					(response) =>
						{
							var t=JSON.parse(atob(response));
							if(response=="NOAUTH")
								{
									this.$store.state.force_auth=true;
									return;
								}
							this.storeCboards(t.filter((cboard)=>cboard!='DUMMY').sort());
							//console.log(this.$data.Cboards);
						},
						async:false
						});
			},
			getInverterModels(){
				$.ajax({
					type: 'POST',
					url: this.$store.datacenter+"/get_inverter_models",
					data: JSON.stringify([this.$store.oauth_token]),
					success:
					(response) =>
						{
							var t=JSON.parse(atob(response));
							if(response=="NOAUTH")
								{
									this.$store.state.force_auth=true;
									return;
								}
							this.storeInverters(t.filter((inverter)=>inverter!='DUMMY').sort());
							//console.log(this.$data.Inverters);
						},
						async:false
						});
			},
			getConstructorCompanies(){
				$.ajax({
					type: 'POST',
					url: this.$store.datacenter+"/get_constructor_companies",
					data: JSON.stringify([this.$store.oauth_token]),
					success:
					(response) =>
						{
							var t=JSON.parse(atob(response));
							if(response=="NOAUTH")
								{
									this.$store.state.force_auth=true;
									return;
								}
							this.storeConstructors(t.filter((constructor)=>constructor!='DUMMY').sort());
							//console.log(this.$data.Constructors);
						},
						async:false
						});
			},
			NewPlant(){
			},
        },
     created()
        {
			this.setTitle("new Plant");
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

