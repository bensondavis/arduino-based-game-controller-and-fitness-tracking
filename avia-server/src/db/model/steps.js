import {Schema, model} from 'mongoose'

const steps = new Schema({
  createAt: { type: Date, default: Date.now },
});

const stepsModel = model("steps", steps);

export {stepsModel}
