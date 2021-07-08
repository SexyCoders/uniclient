<template>
  <h3>{{$store.page_title}}</h3>
  <div class="container">
<div class="row">
    <div class="col-lg-4 col-xl-4">
        <div class="card-box text-center">

            <h4 class="mb-0">Customer {{$store.selection.ID}}</h4>

            <button type="button" class="btn btn-success btn-xs waves-effect mb-2 waves-light">Edit</button>
            <button type="button" class="btn btn-danger btn-xs waves-effect mb-2 waves-light">Delete</button>

            <div class="text-left mt-3">
                <h5 class="font-13 text-uppercase">Details:</h5>
                <p class="text-muted mb-2 font-13"><strong>Company :</strong> 
                    <span class="ml-2 ">{{$store.selection.Company}}</span></p>
                <p class="text-muted mb-2 font-13"><strong>Name :</strong> 
                    <span class="ml-2">{{$store.selection.FirstName+" "+$store.selection.LastName}}</span></p>
                <p class="text-muted mb-1 font-13"><strong>email :</strong> 
                    <span class="ml-2">{{$store.selection.email}}</span></p>
                <p class="text-muted mb-1 font-13"><strong>Phone :</strong> 
                    <span class="ml-2">{{$store.selection.PhoneNumber}}</span></p>
                <p class="text-muted mb-1 font-13"><strong>Address :</strong> 
                    <span class="ml-2">{{$store.selection.Address+" - "+$store.selection.zip}}</span></p>
                <p class="text-muted mb-1 font-13"><strong>TIN :</strong> 
                    <span class="ml-2">{{$store.selection.TIN}}</span></p>
                <p class="text-muted mb-1 font-13"><strong>Notes :</strong> 
                    <span class="ml-2">{{$store.selection.Notes}}</span></p>
            </div>

        </div> <!-- end card-box -->

        <!--<div class="card-box">-->
            <!--<h4 class="header-title">Skills</h4>-->
            <!--<p class="mb-3">Everyone realizes why a new common language would be desirable</p>-->

            <!--<div class="pt-1">-->
                <!--<h6 class="text-uppercase mt-0">HTML5 <span class="float-right">90%</span></h6>-->
                <!--<div class="progress progress-sm m-0">-->
                    <!--<div class="progress-bar bg-purple" role="progressbar" aria-valuenow="90" aria-valuemin="0" aria-valuemax="100" style="width: 90%">-->
                        <!--<span class="sr-only">90% Complete</span>-->
                    <!--</div>-->
                <!--</div>-->
            <!--</div>-->

            <!--<div class="mt-2 pt-1">-->
                <!--<h6 class="text-uppercase">PHP <span class="float-right">67%</span></h6>-->
                <!--<div class="progress progress-sm m-0">-->
                    <!--<div class="progress-bar bg-purple" role="progressbar" aria-valuenow="67" aria-valuemin="0" aria-valuemax="100" style="width: 67%">-->
                        <!--<span class="sr-only">67% Complete</span>-->
                    <!--</div>-->
                <!--</div>-->
            <!--</div>-->

            <!--<div class="mt-2 pt-1">-->
                <!--<h6 class="text-uppercase">WordPress <span class="float-right">48%</span></h6>-->
                <!--<div class="progress progress-sm m-0">-->
                    <!--<div class="progress-bar bg-purple" role="progressbar" aria-valuenow="48" aria-valuemin="0" aria-valuemax="100" style="width: 48%">-->
                        <!--<span class="sr-only">48% Complete</span>-->
                    <!--</div>-->
                <!--</div>-->
            <!--</div>-->

            <!--<div class="mt-2 pt-1">-->
                <!--<h6 class="text-uppercase">Laravel <span class="float-right">95%</span></h6>-->
                <!--<div class="progress progress-sm m-0">-->
                    <!--<div class="progress-bar bg-purple" role="progressbar" aria-valuenow="95" aria-valuemin="0" aria-valuemax="100" style="width: 95%">-->
                        <!--<span class="sr-only">95% Complete</span>-->
                    <!--</div>-->
                <!--</div>-->
            <!--</div>-->

            <!--<div class="mt-2 pt-1">-->
                <!--<h6 class="text-uppercase">ReactJs <span class="float-right">72%</span></h6>-->
                <!--<div class="progress progress-sm m-0">-->
                    <!--<div class="progress-bar bg-purple" role="progressbar" aria-valuenow="72" aria-valuemin="0" aria-valuemax="100" style="width: 72%">-->
                        <!--<span class="sr-only">72% Complete</span>-->
                    <!--</div>-->
                <!--</div>-->
            <!--</div>-->

        <!--</div> [> end card-box<]-->

    </div> <!-- end col-->

    <!--<div class="col-lg-8 col-xl-8">-->
        <!--<div class="card-box">-->
            <!--<ul class="nav nav-pills navtab-bg">-->
                <!--<li class="nav-item">-->
                    <!--<a href="#about-me" data-toggle="tab" aria-expanded="true" class="nav-link ml-0 active">-->
                        <!--<i class="mdi mdi-face-profile mr-1"></i>About Me-->
                    <!--</a>-->
                <!--</li>-->
                <!--<li class="nav-item">-->
                    <!--<a href="#settings" data-toggle="tab" aria-expanded="false" class="nav-link">-->
                        <!--<i class="mdi mdi-settings-outline mr-1"></i>Settings-->
                    <!--</a>-->
                <!--</li>-->
            <!--</ul>-->

            <!--<div class="tab-content">-->

                <!--[><div class="tab-pane show active" id="about-me"><]-->

                    <!--[><h5 class="mb-4 text-uppercase"><i class="mdi mdi-briefcase mr-1"></i><]-->
                        <!--[>Experience</h5><]-->

                    <!--[><ul class="list-unstyled timeline-sm"><]-->
                        <!--[><li class="timeline-sm-item"><]-->
                            <!--[><span class="timeline-sm-date">2015 - 19</span><]-->
                            <!--[><h5 class="mt-0 mb-1">Lead designer / Developer</h5><]-->
                            <!--[><p>websitename.com</p><]-->
                            <!--[><p class="text-muted mt-2">Everyone realizes why a new common language<]-->
                                <!--[>would be desirable: one could refuse to pay expensive translators.<]-->
                                <!--[>To achieve this, it would be necessary to have uniform grammar,<]-->
                                <!--[>pronunciation and more common words.</p><]-->

                        <!--[></li><]-->
                        <!--[><li class="timeline-sm-item"><]-->
                            <!--[><span class="timeline-sm-date">2012 - 15</span><]-->
                            <!--[><h5 class="mt-0 mb-1">Senior Graphic Designer</h5><]-->
                            <!--[><p>Software Inc.</p><]-->
                            <!--[><p class="text-muted mt-2">If several languages coalesce, the grammar<]-->
                                <!--[>of the resulting language is more simple and regular than that of<]-->
                                <!--[>the individual languages. The new common language will be more<]-->
                                <!--[>simple and regular than the existing European languages.</p><]-->
                        <!--[></li><]-->
                        <!--[><li class="timeline-sm-item"><]-->
                            <!--[><span class="timeline-sm-date">2010 - 12</span><]-->
                            <!--[><h5 class="mt-0 mb-1">Graphic Designer</h5><]-->
                            <!--[><p>Coderthemes LLP</p><]-->
                            <!--[><p class="text-muted mt-2 mb-0">The European languages are members of<]-->
                                <!--[>the same family. Their separate existence is a myth. For science<]-->
                                <!--[>music sport etc, Europe uses the same vocabulary. The languages<]-->
                                <!--[>only differ in their grammar their pronunciation.</p><]-->
                        <!--[></li><]-->
                    <!--[></ul><]-->

                    <!--[><h5 class="mb-3 mt-4 text-uppercase"><i class="mdi mdi-cards-variant mr-1"></i><]-->
                        <!--[>Projects</h5><]-->
                    <!--[><div class="table-responsive"><]-->
                        <!--[><table class="table table-borderless mb-0"><]-->
                            <!--[><thead class="thead-light"><]-->
                                <!--[><tr><]-->
                                    <!--[><th>#</th><]-->
                                    <!--[><th>Project Name</th><]-->
                                    <!--[><th>Start Date</th><]-->
                                    <!--[><th>Due Date</th><]-->
                                    <!--[><th>Status</th><]-->
                                    <!--[><th>Clients</th><]-->
                                <!--[></tr><]-->
                            <!--[></thead><]-->
                            <!--[><tbody><]-->
                                <!--[><tr><]-->
                                    <!--[><td>1</td><]-->
                                    <!--[><td>App design and development</td><]-->
                                    <!--[><td>01/01/2015</td><]-->
                                    <!--[><td>10/15/2018</td><]-->
                                    <!--[><td><span class="badge badge-info">Work in Progress</span></td><]-->
                                    <!--[><td>Halette Boivin</td><]-->
                                <!--[></tr><]-->
                                <!--[><tr><]-->
                                    <!--[><td>2</td><]-->
                                    <!--[><td>Coffee detail page - Main Page</td><]-->
                                    <!--[><td>21/07/2016</td><]-->
                                    <!--[><td>12/05/2018</td><]-->
                                    <!--[><td><span class="badge badge-success">Pending</span></td><]-->
                                    <!--[><td>Durandana Jolicoeur</td><]-->
                                <!--[></tr><]-->
                                <!--[><tr><]-->
                                    <!--[><td>3</td><]-->
                                    <!--[><td>Poster illustation design</td><]-->
                                    <!--[><td>18/03/2018</td><]-->
                                    <!--[><td>28/09/2018</td><]-->
                                    <!--[><td><span class="badge badge-pink">Done</span></td><]-->
                                    <!--[><td>Lucas Sabourin</td><]-->
                                <!--[></tr><]-->
                                <!--[><tr><]-->
                                    <!--[><td>4</td><]-->
                                    <!--[><td>Drinking bottle graphics</td><]-->
                                    <!--[><td>02/10/2017</td><]-->
                                    <!--[><td>07/05/2018</td><]-->
                                    <!--[><td><span class="badge badge-purple">Work in Progress</span></td><]-->
                                    <!--[><td>Donatien Brunelle</td><]-->
                                <!--[></tr><]-->
                                <!--[><tr><]-->
                                    <!--[><td>5</td><]-->
                                    <!--[><td>Landing page design - Home</td><]-->
                                    <!--[><td>17/01/2017</td><]-->
                                    <!--[><td>25/05/2021</td><]-->
                                    <!--[><td><span class="badge badge-warning">Coming soon</span></td><]-->
                                    <!--[><td>Karel Auberjo</td><]-->
                                <!--[></tr><]-->

                            <!--[></tbody><]-->
                        <!--[></table><]-->
                    <!--[></div><]-->

                <!--[></div><]-->
                <!--[>[> end timeline content<]<]-->

                <!--[><div class="tab-pane" id="settings"><]-->
                    <!--[><form><]-->
                        <!--[><h5 class="mb-3 text-uppercase bg-light p-2"><i class="mdi mdi-account-circle mr-1"></i> Personal Info</h5><]-->

                        <!--[><div class="row"><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="firstname">First Name</label><]-->
                                    <!--[><input type="text" class="form-control" id="firstname" placeholder="Enter first name"><]-->
                                <!--[></div><]-->
                            <!--[></div><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="lastname">Last Name</label><]-->
                                    <!--[><input type="text" class="form-control" id="lastname" placeholder="Enter last name"><]-->
                                <!--[></div><]-->
                            <!--[></div> [> end col <]<]-->
                        <!--[></div> [> end row <]<]-->

                        <!--[><div class="row"><]-->
                            <!--[><div class="col-12"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="userbio">Bio</label><]-->
                                    <!--[><textarea class="form-control" id="userbio" rows="4" placeholder="Write something..."></textarea><]-->
                                <!--[></div><]-->
                            <!--[></div> [> end col <]<]-->
                        <!--[></div> [> end row <]<]-->

                        <!--[><div class="row"><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="useremail">Email Address</label><]-->
                                    <!--[><input type="email" class="form-control" id="useremail" placeholder="Enter email"><]-->
                                    <!--[><span class="form-text text-muted"><small>If you want to change email please <a href="javascript: void(0);">click</a> here.</small></span><]-->
                                <!--[></div><]-->
                            <!--[></div><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="userpassword">Password</label><]-->
                                    <!--[><input type="password" class="form-control" id="userpassword" placeholder="Enter password"><]-->
                                    <!--[><span class="form-text text-muted"><small>If you want to change password please <a href="javascript: void(0);">click</a> here.</small></span><]-->
                                <!--[></div><]-->
                            <!--[></div> [> end col <]<]-->
                        <!--[></div> [> end row <]<]-->

                        <!--[><h5 class="mb-3 text-uppercase bg-light p-2"><i class="mdi mdi-office-building mr-1"></i> Company Info</h5><]-->
                        <!--[><div class="row"><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="companyname">Company Name</label><]-->
                                    <!--[><input type="text" class="form-control" id="companyname" placeholder="Enter company name"><]-->
                                <!--[></div><]-->
                            <!--[></div><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="cwebsite">Website</label><]-->
                                    <!--[><input type="text" class="form-control" id="cwebsite" placeholder="Enter website url"><]-->
                                <!--[></div><]-->
                            <!--[></div> [> end col <]<]-->
                        <!--[></div> [> end row <]<]-->

                        <!--[><h5 class="mb-3 text-uppercase bg-light p-2"><i class="mdi mdi-earth mr-1"></i> Social</h5><]-->
                        <!--[><div class="row"><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="social-fb">Facebook</label><]-->
                                    <!--[><div class="input-group"><]-->
                                        <!--[><div class="input-group-prepend"><]-->
                                            <!--[><span class="input-group-text"><i class="fab fa-facebook-square"></i></span><]-->
                                        <!--[></div><]-->
                                        <!--[><input type="text" class="form-control" id="social-fb" placeholder="Url"><]-->
                                    <!--[></div><]-->
                                <!--[></div><]-->
                            <!--[></div><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="social-tw">Twitter</label><]-->
                                    <!--[><div class="input-group"><]-->
                                        <!--[><div class="input-group-prepend"><]-->
                                            <!--[><span class="input-group-text"><i class="fab fa-twitter"></i></span><]-->
                                        <!--[></div><]-->
                                        <!--[><input type="text" class="form-control" id="social-tw" placeholder="Username"><]-->
                                    <!--[></div><]-->
                                <!--[></div><]-->
                            <!--[></div> [> end col <]<]-->
                        <!--[></div> [> end row <]<]-->

                        <!--[><div class="row"><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="social-insta">Instagram</label><]-->
                                    <!--[><div class="input-group"><]-->
                                        <!--[><div class="input-group-prepend"><]-->
                                            <!--[><span class="input-group-text"><i class="fab fa-instagram"></i></span><]-->
                                        <!--[></div><]-->
                                        <!--[><input type="text" class="form-control" id="social-insta" placeholder="Url"><]-->
                                    <!--[></div><]-->
                                <!--[></div><]-->
                            <!--[></div><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="social-lin">Linkedin</label><]-->
                                    <!--[><div class="input-group"><]-->
                                        <!--[><div class="input-group-prepend"><]-->
                                            <!--[><span class="input-group-text"><i class="fab fa-linkedin"></i></span><]-->
                                        <!--[></div><]-->
                                        <!--[><input type="text" class="form-control" id="social-lin" placeholder="Url"><]-->
                                    <!--[></div><]-->
                                <!--[></div><]-->
                            <!--[></div> [> end col <]<]-->
                        <!--[></div> [> end row <]<]-->

                        <!--[><div class="row"><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="social-sky">Skype</label><]-->
                                    <!--[><div class="input-group"><]-->
                                        <!--[><div class="input-group-prepend"><]-->
                                            <!--[><span class="input-group-text"><i class="fab fa-skype"></i></span><]-->
                                        <!--[></div><]-->
                                        <!--[><input type="text" class="form-control" id="social-sky" placeholder="@username"><]-->
                                    <!--[></div><]-->
                                <!--[></div><]-->
                            <!--[></div><]-->
                            <!--[><div class="col-md-6"><]-->
                                <!--[><div class="form-group"><]-->
                                    <!--[><label for="social-gh">Github</label><]-->
                                    <!--[><div class="input-group"><]-->
                                        <!--[><div class="input-group-prepend"><]-->
                                            <!--[><span class="input-group-text"><i class="fab fa-github"></i></span><]-->
                                        <!--[></div><]-->
                                        <!--[><input type="text" class="form-control" id="social-gh" placeholder="Username"><]-->
                                    <!--[></div><]-->
                                <!--[></div><]-->
                            <!--[></div> [> end col <]<]-->
                        <!--[></div> [> end row <]<]-->

                        <!--[><div class="text-right"><]-->
                            <!--[><button type="submit" class="btn btn-success waves-effect waves-light mt-2"><i class="mdi mdi-content-save"></i> Save</button><]-->
                        <!--[></div><]-->
                    <!--[></form><]-->
                <!--[></div><]-->
                <!--[> end settings content<]-->

            <!--</div> [> end tab-content <]-->
        <!--</div> [> end card-box<]-->

    <!--</div> [> end col <]-->
</div>
</div>
</template>
<script>
import {Time} from "@sexycoders/time.js"
export default {
    components: {
    },
    data() {
        return {
            connection_time:"",
            tracker_time:""
        };
  },
    computed()
        {
        },
    mounted() {
    },
    methods: {
        setTitle(title)
        {
            this.$store.page_title=title;
        },
        },
     created()
        {
        this.setTitle('Customer Profile');
        if(this.$store.selection=='nothing')
            this.$router.push('plants');
        //var t=new Time();
        //t.fromString(this.$store.selection.ConnectionDate);
        //this.connection_time=t.toStringf("dmyl-","c",1);
        //t.fromString(this.$store.selection.TrackerBegin);
        //this.tracker_time=t.toStringf("dmyl-","c",1);
        }
};
</script>
<style scoped>
body{
    color: #6c757d;
    background-color: #f5f6f8;
    margin-top:20px;
}
.card-box {
    background-color: #fff;
    background-clip: border-box;
    border: 1px solid #e7eaed;
    padding: 1.5rem;
    margin-bottom: 24px;
    border-radius: .25rem;
}
.avatar-xl {
    height: 6rem;
    width: 6rem;
}
.rounded-circle {
    border-radius: 50%!important;
}
.nav-pills .nav-link.active, .nav-pills .show>.nav-link {
    color: #fff;
    background-color: #1abc9c;
}
.nav-pills .nav-link {
    border-radius: .25rem;
}
.navtab-bg li>a {
    background-color: #f7f7f7;
    margin: 0 5px;
}
.nav-pills>li>a, .nav-tabs>li>a {
    color: #6c757d;
    font-weight: 600;
}
.mb-4, .my-4 {
    margin-bottom: 2.25rem!important;
}
.tab-content {
    padding: 20px 0 0 0;
}
.progress-sm {
    height: 5px;
}
.m-0 {
    margin: 0!important;
}
.table .thead-light th {
    color: #6c757d;
    background-color: #f1f5f7;
    border-color: #dee2e6;
}
.social-list-item {
    height: 2rem;
    width: 2rem;
    line-height: calc(2rem - 4px);
    display: block;
    border: 2px solid #adb5bd;
    border-radius: 50%;
    color: #adb5bd;
}

.text-purple {
    color: #6559cc!important;
}
.border-purple {
    border-color: #6559cc!important;
}

.timeline {
    margin-bottom: 50px;
    position: relative;
}
.timeline:before {
    background-color: #dee2e6;
    bottom: 0;
    content: "";
    left: 50%;
    position: absolute;
    top: 30px;
    width: 2px;
    z-index: 0;
}
.timeline .time-show {
    margin-bottom: 30px;
    margin-top: 30px;
    position: relative;
}
.timeline .timeline-box {
    background: #fff;
    display: block;
    margin: 15px 0;
    position: relative;
    padding: 20px;
}
.timeline .timeline-album {
    margin-top: 12px;
}
.timeline .timeline-album a {
    display: inline-block;
    margin-right: 5px;
}
.timeline .timeline-album img {
    height: 36px;
    width: auto;
    border-radius: 3px;
}
@media (min-width: 768px) {
    .timeline .time-show {
        margin-right: -69px;
        text-align: right;
    }
    .timeline .timeline-box {
        margin-left: 45px;
    }
    .timeline .timeline-icon {
        background: #dee2e6;
        border-radius: 50%;
        display: block;
        height: 20px;
        left: -54px;
        margin-top: -10px;
        position: absolute;
        text-align: center;
        top: 50%;
        width: 20px;
    }
    .timeline .timeline-icon i {
        color: #98a6ad;
        font-size: 13px;
        position: absolute;
        left: 4px;
    }
    .timeline .timeline-desk {
        display: table-cell;
        vertical-align: top;
        width: 50%;
    }
    .timeline-item {
        display: table-row;
    }
    .timeline-item:before {
        content: "";
        display: block;
        width: 50%;
    }
    .timeline-item .timeline-desk .arrow {
        border-bottom: 12px solid transparent;
        border-right: 12px solid #fff !important;
        border-top: 12px solid transparent;
        display: block;
        height: 0;
        left: -12px;
        margin-top: -12px;
        position: absolute;
        top: 50%;
        width: 0;
    }
    .timeline-item.timeline-item-left:after {
        content: "";
        display: block;
        width: 50%;
    }
    .timeline-item.timeline-item-left .timeline-desk .arrow-alt {
        border-bottom: 12px solid transparent;
        border-left: 12px solid #fff !important;
        border-top: 12px solid transparent;
        display: block;
        height: 0;
        left: auto;
        margin-top: -12px;
        position: absolute;
        right: -12px;
        top: 50%;
        width: 0;
    }
    .timeline-item.timeline-item-left .timeline-desk .album {
        float: right;
        margin-top: 20px;
    }
    .timeline-item.timeline-item-left .timeline-desk .album a {
        float: right;
        margin-left: 5px;
    }
    .timeline-item.timeline-item-left .timeline-icon {
        left: auto;
        right: -56px;
    }
    .timeline-item.timeline-item-left:before {
        display: none;
    }
    .timeline-item.timeline-item-left .timeline-box {
        margin-right: 45px;
        margin-left: 0;
        text-align: right;
    }
}
@media (max-width: 767.98px) {
    .timeline .time-show {
        text-align: center;
        position: relative;
    }
    .timeline .timeline-icon {
        display: none;
    }
}
.timeline-sm {
    padding-left: 110px;
}
.timeline-sm .timeline-sm-item {
    position: relative;
    padding-bottom: 20px;
    padding-left: 40px;
    border-left: 2px solid #dee2e6;
}
.timeline-sm .timeline-sm-item:after {
    content: "";
    display: block;
    position: absolute;
    top: 3px;
    left: -7px;
    width: 12px;
    height: 12px;
    border-radius: 50%;
    background: #fff;
    border: 2px solid #1abc9c;
}
.timeline-sm .timeline-sm-item .timeline-sm-date {
    position: absolute;
    left: -104px;
}
@media (max-width: 420px) {
    .timeline-sm {
        padding-left: 0;
    }
    .timeline-sm .timeline-sm-date {
        position: relative !important;
        display: block;
        left: 0 !important;
        margin-bottom: 10px;
    }
}
</style>

