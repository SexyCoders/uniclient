<template>
    <div id="booking" class="section" style="height:600px">
	<h3>{{$store.page_title}}</h3>
		<div class="section-center">
			<div class="container">
				<div class="row">
					<div class="booking-form">
						<form>
							<div class="row">
								<div class="col-md-2">
									<div class="form-group">
										<span class="form-label"><b>Registry ID</b></span>
										<span class='form-label'> {{this.$store.selection.reg_id}} </span>
									</div>
								</div>
								<div class="col-md-3">
									<div class="form-group">
										<span class="form-label"><b>Plant</b></span>
										<span class="form-label">{{this.$store.selection.plant_id}}</span>
									</div>
								</div>
								<div class="col-md-2">
									<div class="form-group">
										<span class="form-label"><b>Reported Date</b></span>
										<span class="form-label">15/7/21</span>
									</div>
								</div>
								<div class="col-md-2">
									<div class="form-group">
										<span class="form-label"><b>Assigned Mech</b></span>
										<span class="form-label">{{this.$store.selection.AssignedMech}}</span>
									</div>
								</div>
							</div>
								<br>
								<br>
							<div class="row">
								<div class="col-md-12">
									<div class="form-group">
										<span class="form-label"><b>Notes</b></span>
										<span class="form-label">{{this.$store.selection.ErrorNotes}}</span>
									</div>
								</div>
							</div>
								<br>
								<br>
							<div class="row">
								<div class="col-md-12">
									<div class="form-group">
										<span class="form-label"><b>Mech Notes</b></span>
										<input class="form-control" type="text" placeholder="plaintext" v-model="Notes">
									</div>
								</div>
							</div>
							<div class="row">
								<div class="col-md-1" v-if="this.$store.selection.stored==='false'">
									<div class="form-btn">
										<button type="button" class="btn btn-success" @click='tempError();'>store</button>
									</div>
								</div>
								<div class="col-md-1">
									<div class="form-btn">
										<button type="button" class="btn btn-danger" @click='resolveError();'>FINAL</button>
									</div>
								</div>
								<span class="form-label"><b> Aprox.Time 23:33</b></span>
							</div>
						</form>
					</div>
				</div>
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
			ID:"",
			Notes:""
		}
  },
    computed()
        {
        },
    mounted() {
		if(this.$store.selection.stored=="true")
			this.getNotes();
    },
    methods: 
		{
			tempError()
				{
					this.$data.ID=this.$store.selection.reg_id;
					var senddata = Object.assign({},this.$data);
					senddata.token=window.__auth_system.oauth2.token;
					senddata=JSON.stringify(Object.values(senddata));
					console.log(senddata);
					$.ajax({
						type: 'POST',
						url: window.__SCD.datacenter+"/temp_error",
						data:senddata, 
						success:
						(response) =>
							{
                                var t=JSON.parse(response);
                                if(response=="NOAUTH")
                                    {
                                        this.$store.state.NOAUTH=true;
                                        return;
                                    }
								else
									{
										alert("Error "+t.reg_id+" succcesfully stored.");
										this.$router.push("errors");
									}
								console.log(response);
							},
							async:false
							});
				},
			resolveError()
				{
					this.$data.ID=this.$store.selection.reg_id;
					var senddata = Object.assign({},this.$data);
					senddata.stored=this.$store.selection.stored;
					senddata.token=window.__auth_system.oauth2.token;
					senddata=JSON.stringify(Object.values(senddata));
					console.log(senddata);
					$.ajax({
						type: 'POST',
						url: window.__SCD.datacenter+"/resolve_error",
						data:senddata, 
						success:
						(response) =>
							{
                                var t=JSON.parse(response);
                                if(response=="NOAUTH")
                                    {
                                        this.$store.state.NOAUTH=true;
                                        return;
                                    }
								else
									{
										alert("Error "+t.reg_id+" succcesfully resolved.");
										this.$router.push("errors");
									}
								console.log(response);
							},
							async:false
							});
				},
			setTitle(title)
				{
					this.$store.page_title=title;
				},
			getNotes()
				{
					this.$data.Notes=this.$store.selection.MechNotes;
				}
        },
     created()
        {
			this.setTitle('Store or Resolve Error');
        }
};
</script>
<style scoped>
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

