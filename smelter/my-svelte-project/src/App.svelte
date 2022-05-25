<script>

	import Module from "../../../a.out";
	import { onMount } from 'svelte';

	let helloWorld;
	let fibb;
	let number = 0, numberJs = 0;
	let fibbRes = '', fibbResJs = '';
	let hello = '';
	var startTime, endTime;
	let seconds = '', secondsJs = '';

	onMount(() => {
		Module().then((ok)=>{
			helloWorld = ok.cwrap('helloWorld', 'string', []);
			fibb = ok.cwrap('fibb', 'number', ['number']);
		})
	});

	function start() {
		startTime = performance.now();
	};

	function end() {
		endTime = performance.now();
		var timeDiff = endTime - startTime;
		return Math.round(timeDiff);
	}
	function fibbJs(numberJs)
	{
		if(numberJs <= 1)
      		return 0;
		let curr = 1, prev = 0, pom = 0;
		for(let i=2; i<numberJs; i++)
		{
			pom = curr;
			curr += prev;
			prev = pom;
		}
		return curr;
	}

	function native()
	{
		hello = helloWorld()
	}
	function native2()
	{
		start()
		fibbRes = fibb(BigInt(number))
		seconds = end()
	}
	function native3()
	{
		start()
		fibbResJs = fibbJs(numberJs)
		secondsJs = end()
	}
</script>

<main>
	<div>
		<h2>Hello World</h2>
		<button on:click={native}>Hello World</button>
		<span>{hello}</span>
	</div>
	
	<div>
		<h2>Fibbonaci written in c using webassembly</h2>
		<input style="text-align: center;" type="number" bind:value={number}>
		<button on:click={native2}>Fibbonaci wasm</button>
		<span>Result: {fibbRes}</span>
		<span>Time (ms): {seconds}</span>

	</div>

	<div>
		<h2>Fibbonaci written in javascript</h2>
		<input style="text-align: center;" type="number" bind:value={numberJs}>
		<button on:click={native3}>Fibbonaci javascript</button>
		<span>Result: {fibbResJs}</span>
		<span>Time (ms): {secondsJs}</span>

	</div>

	
</main>

<style>
	main {
		text-align: center;
		padding: 1em;
		max-width: 240px;
		margin: auto;
		display: flex;
		flex-direction: column;
		justify-content: space-between;
	}

	h1 {
		color: #ff3e00;
		text-transform: uppercase;
		font-size: 4em;
		font-weight: 100;
	}
	
	div{
		padding-bottom: 3vw;
		display: flex;
		flex-direction: column;
		text-align: center;
	}
	@media (min-width: 640px) {
		main {
			max-width: 30vw;
		}
	}
</style>