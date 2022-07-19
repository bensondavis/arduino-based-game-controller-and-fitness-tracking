import express from "express";
import dotenv from "dotenv";
import cors from "cors";

import { init as initDb } from "./db/init";
import { addStep, calcStepsCount } from "./controllers/steps";

if (process.env.NODE_ENV !== "production") {
    dotenv.config();
  }

const app = express();
const port = process.env.PORT;

app.use(cors())

initDb().catch((e)=>console.log('initDb error', e));

app.get("/health", (req, res) => {
  res.status(200).send("ok");
});

app.get("/steps/add", addStep);

app.get("/steps/count",calcStepsCount)

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});
