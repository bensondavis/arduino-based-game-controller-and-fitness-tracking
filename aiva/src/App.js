import "./App.css";
import { useState, useEffect } from "react";
import SearchAppBar from "./components/AppBar";
import {getStepCount} from './api/steps'


function App() {
  const [steps, setSteps] = useState(0);

  async function updateSteps(){
    const startAt = Date.now() - (3600 * 1000);
    const {count}=await getStepCount(startAt,Date.now());
    setSteps(count);
  }

  useEffect(() => {
    updateSteps()
    const interval = setInterval(() => {
      updateSteps();
    }, 3000);
    return () => clearInterval(interval);
  }, []);

  return (
    <div>
      <SearchAppBar />
      <div className="App">
        <div className="box">
          <div className="values">
            <h5>Step Count</h5>
          </div>
          <div className="values">
            <h1>{steps}</h1>
          </div>
        </div>

        <div className="space"></div>

        <div className="box">
          <div className="values">
            <h5>Calorie's Burned</h5>
          </div>
          <div className="values">
            <h1>{steps / 20}</h1>
          </div>
        </div>
      </div>
    </div>
  );
}

export default App;