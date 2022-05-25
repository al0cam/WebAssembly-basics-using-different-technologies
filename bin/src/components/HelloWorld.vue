<template>
  <div class="hello">
    <button @click="noPls">whatever</button>
  </div>



</template>

<script>
import Module from '../assets/code/a.out';
let bruv;


export default {
  name: 'HelloWorld',
  data(){
  },
  props: {
    msg: String
  },
  mounted(){
    console.log("YEAH")
  },
  methods: {
  noPls(){
    console.log("Ok")
    Module().then((ok)=>{
			this.bruv = ok.cwrap('bruv', 'string', []);
			console.log(ok.cwrap('bruv', 'string', []));
			console.log("HUH:"+bruv);
			console.log(ok.ccall('bruv', 'string', [],[]));
		})
  }
}

};



</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
megi{
  color:rebeccapurple;
  background-color: red;
  
}


</style>
